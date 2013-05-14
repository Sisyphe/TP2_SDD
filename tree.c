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
	
	int index = 0;
	
	while (treeString[index] != '\0')
	{		
		
		if (isOpenedParanthese(treeString[index]))
		{
			index++; /* Car suivant */
			
			/* addChild */			
			addChild(currentNode, treeString[index]);
			
			/* empiler */
			pushStack(stack, currentNode);
		}
		else if (isClosedParanthese(treeString[index]))
		{
			
			/* depiler */
			currentNode = popStack(stack);
			
			if (! isClosedParanthese(treeString[index]))
			{
				index++;
				
				/* addSibling */
				addSibling(currentNode, treeString[index]);
			}
		}
		else if (isComma(treeString[index]))
		{
			index++;
	
			/* addSibling */
			addSibling(currentNode, treeString[index]);
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
