#include "stack.h"
#include <stdio.h>

stack_t * createStack(size_t capacity)
{
    stack_t * stack=malloc(sizeof(stack_t));

    if(stack)
    {
        stack->head=malloc(sizeof(stack_item_t)*capacity);

        if(stack->head)
        {
            stack->size=0;
            stack->capacity=capacity;
            stack->topIndex=0;
        }
        else
        {
            free(stack);
        }
    }

    return stack;
}

int isEmpty(stack_t stack)
{
    return !stack.size;
}

int isFull(stack_t stack)
{
    return stack.size>=stack.capacity;
}

stack_item_t * popStack(stack_t * stack)
{
    stack_item_t * item=0;

    if(!isEmpty(*stack))
    {
        (*item)=stack->head[stack->topIndex];

        --(stack->size);
        --(stack->topIndex);
    }

    return item;
}

int pushStack(stack_t * stack, stack_item_t item)
{
    int exit;

    if(isFull(*stack))
    {
        exit=FAIL;
    }
    else
    {
        *(stack->head+stack->topIndex)=item;

        ++(stack->size);
        ++(stack->topIndex);

        exit=SUCCESS;
    }

    return exit;
}

void printStack(stack_t stack)
{
    unsigned int i;

    printf("%d items of %d in the stack\n", (int)stack.size, (int)stack.capacity);

    for(i=0;i<stack.size;++i)
    {
        printf("Item %d: %d\n",i,*(stack.head+i));
    }
}
