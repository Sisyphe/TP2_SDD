/*
 * @author Gerald Lelong / Noel Martignoni
 * @date 2013-04-16
 *
 * @file tree.c
 * @brief fichier d'entete de gestion des arbres
 *
 */

#include "tree.h"
#include "tools.h"
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

node_t * createNode()
{
    node_t * node = malloc(sizeof(node_t));

    if(node)
    {
        node->child = 0;
        node->sibling = 0;
    }

    return node;
}

node_t * initNode(tree_item_t item)
{
    node_t * node = malloc(sizeof(node_t));

    if(node)
    {
        node->item = item;
        node->child = 0;
        node->sibling = 0;
    }

    return node;
}

int addChild(node_t * node, tree_item_t item)
{
    int exit;

    if(node)
    {
        if(node->child)
        {
            addSibling(node->child, item);
        }
        else
        {
            node_t * new_child = initNode(item);
            node->child = new_child;
        }

        exit = 1;
    }
    else exit = 0;

    return exit;
}

int addSibling(node_t * node, tree_item_t item)
{
    int exit;
    node_t * new_sibling;
    node_t * sibling = node;

    if(node)
    {
        new_sibling = initNode(item);

        while(sibling->sibling != 0)
        {
            sibling = sibling->sibling;
        }

        sibling->sibling = new_sibling;

        exit = 1;
    }
    else exit = 0;

    return exit;
}

void printTree(node_t * node)
{
    int exit = 0;
    queue_t * queue = createQueue(100);

    while(!exit)
    {
        while(node)
        {
            printf("%c ", node->item);
            pushQueue(queue, node);
            node = node->sibling;
        }

        if(!isEmpty(queue))
        {
            printf("\n");
            node = (*popQueue(queue))->child;
        }

        else exit = 1;
    }
}
