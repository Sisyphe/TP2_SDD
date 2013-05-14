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
#include <string.h>

#include "tree.h"
#include "tools.h"
#include "queue.h"
#include "stack.h"

void buildTree(node_t ** dico, char * treeString)
{
    stack_t * stack = createStack(50);

    node_t * currentNode = *dico;
    node_t * nextNode = NULL;

    int index = 0;

    while (treeString[index] != '\0')
    {

        if (isOpenedParanthese(treeString[index]))
        {
            index++; /* Car suivant */

			printf("openPar %c \n", treeString[index]);
			
            /* addChild */
            nextNode = addChild(currentNode, treeString[index]);

            /* empiler */
            pushStack(stack, currentNode);
            
            /* change current */
            currentNode = nextNode;
        }
        else if (isClosedParanthese(treeString[index]))
        {
			index++;
			
			printf("closedPar %c \n", treeString[index]);
			
            /* depiler */
            currentNode = popStack(stack);
            printf("depil %c\n", currentNode->item);

            if (! isClosedParanthese(treeString[index]))
            {
                printf("closedPar2 %c \n", treeString[index]);

                /* addSibling */
                currentNode = addSibling(currentNode, treeString[index]);
            }
        }
        else if (isComma(treeString[index]))
        {
            index++;

            /* addSibling */
            currentNode = addSibling(currentNode, treeString[index]);
        }

        index++;

    }
}

int isOpenedParanthese(char car)
{
    return car == '(';
}

int isClosedParanthese(char car)
{
    return car == ')';
}

int isComma(char car)
{
    return car == ',';
}

void insertWord(char * word)
{
    unsigned int index = 0;
    unsigned int wordSize = strlen(word);

    while (index < wordSize)
    {
        printf("%c\n", word[index]);
        index++;
    }


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

    printf("\n>>> PRINT TREE <<<\n\n");

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
}
