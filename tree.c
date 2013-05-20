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
#include <ctype.h>

#include "tree.h"
#include "tools.h"
#include "queue.h"
#include "stack.h"

node_t * buildTree(char * treeString)
{
    stack_tt * stack = createStack(50);

    node_t * dico = createNode();
    node_t * currentNode = dico;
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
                if (! isClosedParanthese(treeString[index]))
                    currentNode = addSibling(currentNode, treeString[index]);
                break;
                
            case ',':
                currentNode = addSibling(currentNode, treeString[index]);
                break;
        }
        index++;
    }
    
    return dico;
}

int isClosedParanthese(char car)
{
    return car == ')';
}

void insertWord(node_t ** dico, char * word)
{
    unsigned int index = 0;
    size_t wordSize = strlen(word);
    unsigned int lastIndex = (unsigned int)wordSize-1;
    
    char currentCharacter;
    
    node_t ** prevNode = &(*dico)->child;
    node_t * currentNode = *prevNode;
   
    
    printf("EXEC insertWord \n\n");

    while (index < wordSize)
    {
        currentCharacter = word[index];
        
        /* rechercher la lettre dans dico */
        while (currentNode != NULL && characterAreInferior(currentNode->item, currentCharacter))
        {
            printf("%d - %d\n", currentNode->item, currentCharacter);
            prevNode = &currentNode->sibling;
            currentNode = *prevNode;
        }
        
        /* si il n'existe pas on le creee */
        if (currentNode == NULL || characterAreSuperior(currentNode->item, currentCharacter))
        {
            node_t * newNode = initNode(currentCharacter);
            newNode->sibling = currentNode;
            newNode->child = NULL;
            *prevNode = newNode;
        }
        
        if (index == lastIndex)
        {
            printf("last %c\n", (*prevNode)->item);
            (*prevNode)->item = toupper((*prevNode)->item);
        }
        
        /* on rentre dedans */
        prevNode = &(*prevNode)->child;
        currentNode = *prevNode;
        
        index++; /* passe a la lettre suivante */
    }
}

int characterAreInferior(char one, char two)
{
    return toupper(one) < toupper(two);
}

int characterAreSuperior(char one, char two)
{
    return toupper(one) > toupper(two);
}



void printDictionnary(node_t * dico)
{
    int i;
    int exit = 0;
    stack_tt * stack = createStack(100);
    node_t * node = dico;

    printf("\n>>> PRINT DICO <<<\n\n");

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

            if(!node->child)
            {
                for(i = 0; i <= stack->topIndex; ++i)
                {
                    printf("%c", stack->head[i]->item);
                }
                printf("%c\n", node->item);
            }

            node = node->sibling;
        }
        else exit = 1;
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
