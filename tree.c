/**
* @author Gerald Lelong / Noel Martignoni
* @date 2013-04-16
*
* @file tree.c
* @brief fichier d'entete de gestion des arbres
*
*/

#include <stdlib.h>
#include <stdio.h>

#include "tree.h"
#include "tools.h"
#include "queue.h"
#include "stack.h"

node_t * buildTree(char * treeString)
{
    stack_tt * stack = createStack(50);

    node_t * tree = createNode();
    node_t * currentNode = tree;
    node_t * nextNode = NULL;
    
    char currentCharacter;
    int index = 0;

    while (treeString[index] != '\0')
    {        
        currentCharacter = treeString[index];
        index++;
        
        switch (currentCharacter)
        {
            case '(':
                nextNode = addChild(currentNode, treeString[index]);
                pushStack(stack, currentNode);
                currentNode = nextNode;
                break;
                
            case ')':
                currentNode = popStack(stack);
                if (treeString[index] != ')')
                    currentNode = addSibling(currentNode, treeString[index]);
                break;
                
            case ',':
                currentNode = addSibling(currentNode, treeString[index]);
                break;
        }
        index++;
    }
    
    freeStack(stack);
    
    return tree;
}

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

node_t * addChild(node_t * node, tree_item_t item)
{
    node_t * new_child=0;

    if(node)
    {
        if(node->child)
        {
            new_child = addSibling(node->child, item);
        }
        else
        {
            new_child = initNode(item);
            node->child = new_child;
        }
    }

    return new_child;
}

node_t * addSibling(node_t * node, tree_item_t item)
{
    node_t * new_sibling = 0;
    node_t * sibling = node;

    if(node)
    {
        new_sibling = initNode(item);

        while(sibling->sibling != 0)
        {
            sibling = sibling->sibling;
        }

        sibling->sibling = new_sibling;
    }

    return new_sibling;
}

void printTree(node_t * node)
{
    int exit = 0;
    queue_t * queue = createQueue(100);

    printf(">>> PRINT TREE <<<\n\n");

    while(!exit)
    {
        while(node)
        {
            printf("%c ", node->item);
            pushQueue(queue, node);
            node = node->sibling;
        }

        if(!isQueueEmpty(queue))
        {
            node = *popQueue(queue);
            if(node->child)
            {
                if(node->child->sibling)
                    printf("\nChildren of %c: \n", node->item);
                else
                    printf("\nChild of %c: \n", node->item);
            }
            node = node->child;
        }

        else exit = 1;
    }

    printf("\n");
    
    freeQueue(queue);
}

void freeTree(node_t * node)
{
    int exit = 0;
    stack_tt * stack = createStack(100);
    node_t * tmp_node;

    while(!exit)
    {
        while(node)
        {
            pushStack(stack, node);
            node = node->child;
        }

        if(!isStackEmpty(*stack))
        {
            node = popStack(stack);
            tmp_node = node;
            node = node->sibling;
            free(tmp_node);
        }
        else exit = 1;
    }
    
    freeStack(stack);
}