/*
 * @author Gerald Lelong / Noel Martignoni
 * @date 2013-04-16
 * 
 * @file queue.c
 * @brief fichier d'entete de gestion des files
 * 
 */

/*
 * Fonction de creation de file
 */
queue_t * createQueue(size_t size)
{
	queue = (queue_t) malloc(sizeof(queue_t));
	
	if (queue)
	{
		queue->items = (queueItem_t) malloc(sizeof(queueItem_t)*size);
		
		if (queue->items)
		{
			queue->size = size;
			queue->indexStart = 0;
			queue->indexEnd = 0;
			error = SUCCESS;
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
	int error = FAIL;
	
	if (! isFull(queue))
	{
		queue->items[queue->indexEnd] = item;
		if (queue->indexEnd + 1 % queue->size == 0)
		{
			queue->indexEnd = 0;
		else
		{
			queue->indexEnd++;
		}
		
		error = SUCCESS;
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
		item = queue->items[indexStart];
		
		if (queue->indexStart + 1 % queue->size == 0)
		{
			queue->indexStart = 0;
		else
		{
			queue->indexStart++;
		}
	}
	
	return item;
}

/*
 * Fonction pour verifier si la file est vide
 */
int isEmpty(queue_t * queue)
{
	return queue->indexStart == queue->indexEnd;
}

/*
 * Fonction pour verifier si la file est pleine
 */
int isFull(queue_t * queue)
{
	return (queue->indexStart == (queue->indexEnd%queue->size)+1 ;
}

/*
 * Fonction pour afficher une pile
 */
void printQueue(queue_t * queue)
{
	unsigned int index = indexStart;
	
	while (index != indexEnd)
	{
		printf("%d - %d\n", index, queue->items[index]);
		if (index + 1 % queue->size == 0)
		{
			index = 0;
		else
		{
			index++;
		}
	}
}
