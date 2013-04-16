#include <stdio.h>
#include "stack.h"

int main()
{
    stack_t * stack=createStack(10);
    printStack(*stack);
    return 0;
}
