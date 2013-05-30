/**
 * @file stack.c
 *
 * @author Gerald lelong / Noel Martignoni
 * @date 2013-04-16
 *
 * @brief
 * Implemente les fonctions de base de manipulation
 * des piles.
*/

#include "stack.h"
#include <stdio.h>

stack_t * createStack(size_t capacity)
{
    stack_t * stack = malloc(sizeof(stack_t));

    if(stack)
    {
        stack->head = malloc(sizeof(stack_item_t)*capacity);

        if(stack->head)
        {
            stack->capacity=capacity;
            stack->topIndex=-1;
        }
        else
        {
            free(stack);
        }
    }

    return stack;
}

int isStackEmpty(stack_t stack)
{
    return stack.topIndex==-1;
}

int isStackFull(stack_t stack)
{
    return stack.topIndex+1>=(int)stack.capacity;
}

stack_item_t popStack(stack_t * stack)
{
    stack_item_t * item = NULL;

    if(!isStackEmpty(*stack))
    {
        item = stack->head+stack->topIndex;
        --stack->topIndex;
    }

    return *item;
}

int pushStack(stack_t * stack, stack_item_t item)
{
    int exit;

    if(isStackFull(*stack))
    {
        exit=FAIL;
    }
    else
    {
        ++stack->topIndex;
        *(stack->head+stack->topIndex)=item;

        exit=SUCCESS;
    }

    return exit;
}

void printStack(stack_t stack)
{
    int i;

    printf("%d items of %d in the stack\n", stack.topIndex+1, (int)stack.capacity);

    for(i=0;i<=stack.topIndex;++i)
    {
        printf("Item %d: %c\n",i,(*(stack.head+i))->item);
    }
}

void freeStack(stack_t * stack)
{
    free(stack->head);
    free(stack);
}
