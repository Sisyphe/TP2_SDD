/**
 * @file dictionnary.c
 *
 * @author Gerald lelong / Noel Martignoni
 * @date 2013-05-21
 *
 * @brief
 * Implémente les fonctions en rapport avec les dictionnaires
*/

#include "dictionnary.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "tree.h"
#include "tools.h"
#include "stack.h"

Dict createDict()
{
    return initNode(' ');
}

void insertWord(Dict * dico, char * word)
{
    unsigned int index = 0;
    size_t wordSize = strlen(word);
    unsigned int lastIndex = (unsigned int)wordSize-1;
    
    char currentCharacter;
    
    node_t ** prevNode = &(*dico)->child;
    node_t * currentNode = *prevNode;

    while (index < wordSize)
    {
        currentCharacter = word[index];
        
        /* rechercher la lettre dans dico */
        while (currentNode != NULL && characterAreInferior(currentNode->item, currentCharacter))
        {
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

void printDict(Dict dict)
{
    int i;
    int exit = 0;
    stack_tt * stack = createStack(100);
    node_t * node = dict;

    printf(">>> DICTIONNARY <<<\n\n");

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

            if(isupper(node->item))
            {
                for(i = 1; i <= stack->topIndex; ++i)
                {
                    printf("%c", stack->head[i]->item);
                }
                printf("%c\n", tolower(node->item));
            }

            node = node->sibling;
        }
        else exit = 1;
    }
}