/*
 * @author Gerald Lelong / Noel Martignoni
 * @date 2013-04-16
 * 
 * @file queue.c
 * @brief fichier d'entete de gestion des files
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "queue.h"

/*
 * Fonction de creation de file
 */
queue_t * createQueue(int size)
{
	queue_t * queue = (queue_t *) malloc(sizeof(queue_t));
	
	if (queue)
	{
		queue->items = (queueItem_t *) malloc(sizeof(queueItem_t)*size);
		
		if (queue->items)
		{
			queue->size = size;
			queue->indexStart = 0;
			queue->indexEnd = 0;
            queue->nbElement = 0;
		}
		else
		{
			free(queue);
		}
	}
	
	return queue;
}

/*
 * Fonction pour emfiler un element
 */
int pushQueue(queue_t * queue, queueItem_t item)
{
	int error = 1;
	
	if (! isQueueFull(queue))
	{
		queue->items[queue->indexEnd] = item;
        
		if ((queue->indexEnd+1) % queue->size == 0)
		{
			queue->indexEnd = 0;
        }
		else
		{
			queue->indexEnd++;
		}
		
        queue->nbElement++;
		error = 0;
	}
	
	return error;
}

/*
 * Fonction pour defiler un element
 */
queueItem_t * popQueue(queue_t * queue)
{	
	queueItem_t * item = NULL;
	
	if (! isQueueEmpty(queue))
	{
		item = &queue->items[queue->indexStart];
		
		if ((queue->indexStart+1) % queue->size == 0)
		{
			queue->indexStart = 0;
        }
		else
		{
			queue->indexStart++;
		}
        
        queue->nbElement--;
	}
	
	return item;
}

/*
 * Fonction pour verifier si la file est vide
 */
int isQueueEmpty(queue_t * queue)
{
	return queue->nbElement == 0;
}

/*
 * Fonction pour verifier si la file est pleine
 */
int isQueueFull(queue_t * queue)
{
	return queue->nbElement == queue->size;
}

/*
 * Fonction pour afficher une pile
 */
void printQueue(queue_t * queue)
{
	unsigned int index = queue->indexStart;
    unsigned int nbElementNotPrinted = queue->nbElement;
	
    printf("\n*** File ***\n\n");
    
    printf("indexStart : %d\n", queue->indexStart);
    printf("indexEnd : %d\n", queue->indexEnd);
    printf("size : %d\n", queue->size);
    printf("nbElement : %d\n", queue->nbElement);
    printf("isQueueFull : %s\n", (isQueueFull(queue)?"TRUE":"FALSE"));
    printf("\n");
    
    if (isQueueEmpty(queue))
    {
        printf("File vide\n");
    }
    else
    {
        printf("File : |");
        while (nbElementNotPrinted > 0)
        {
            printf(" %d (%d) |", queue->items[index]->item, index);
            
            if ((index+1) % queue->size == 0)
            {
                index = 0;
            }
            else
            {
                index++;
            }
            
            nbElementNotPrinted--;
        }
        printf("\n");
    }
}

void freeQueue(queue_t * queue)
{
    free(queue->items);
    free(queue);
}
