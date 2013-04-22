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
	int error = 0;
	
	if (! isFull(queue))
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
		error = 1;
	}
	
	return error;
}

/*
 * Fonction pour defiler un element
 */
queueItem_t * popQueue(queue_t * queue)
{	
	queueItem_t * item = NULL;
	
	if (! isEmpty(queue))
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
int isEmpty(queue_t * queue)
{
	return queue->nbElement == 0;
}

/*
 * Fonction pour verifier si la file est pleine
 */
int isFull(queue_t * queue)
{
	return queue->nbElement == queue->size;
}

/*
 * Fonction pour afficher une pile
 */
void printQueue(queue_t * queue)
{
	unsigned int index = queue->indexStart;
	
    printf("\n*** File ***\n");
    
    if (isEmpty(queue))
        printf("File vide\n");
    
    printf("indexStart : %d \nindexEnd : %d \nsize : %d \nnbElement : %d\n", queue->indexStart, queue->indexEnd, queue->size, queue->nbElement);
    
	while (index != queue->indexEnd)
	{
		printf("%d - %d\n", index, queue->items[index]);
		if (index + 1 % queue->size == 0)
		{
			index = 0;
        }
		else
		{
			index++;
		}
	}
    
    index = 0;
    printf("|");
    while (index < queue->size)
    {
        printf(" %d |", queue->items[index]);
        index++;
    }
    printf("\n");
}
