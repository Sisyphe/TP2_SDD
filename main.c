#include <stdio.h>
#include "queue.h"

int main()
{
    queue_t * queue = createQueue(10);
    
    printQueue(queue);
    
    return 0;
}
