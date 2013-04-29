/*
 * @author Gerald lelong / Noel Martignoni
 * @date 2013-04-16
 *
 * @file stack.h
 * Définit les fonctions de base de manipulation
 * des piles
*/

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "tools.h"

typedef int stack_item_t;
typedef struct
{
    stack_item_t * head;
    size_t size;
    size_t capacity;
    unsigned int topIndex;
} stack_t;

stack_t * createStack(size_t capacity);

int isStackEmpty(stack_t stack);
int isStackFull(stack_t stack);

stack_item_t popStack(stack_t * stack);
int pushStack(stack_t * stack, stack_item_t item);

void printStack(stack_t stack);

#endif
