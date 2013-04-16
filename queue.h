/*
 * @author Gerald Lelong / Noel Martignoni
 * @date 2013-04-16
 * 
 * @file queue.h
 * Definit les fonctions de base de manipulation 
 * des files
 */

#ifndef QUEUE_H
#define QUEUE_H

/*
 * @typedef Element de la file
 */
typedef int queueItem_t;

/*
 * @typedef Structure de la file
 */
typedef struct
{
	queueItem_t * items;
	size_t size;
	unsigned int indexStart;
	unsigned int indexEnd;
} queue_t;

/*
 * Fonction de creation de file
 */
queue_t * createQueue(size_t size);

/*
 * Fonction pour emfiler un element
 */
int pushQueue(queue_t * queue, queueItem_t item);

/*
 * Fonction pour defiler un element
 */
int popQueue(queue_t * queue, queueItem_t ** item);

/*
 * Fonction pour verifier si la file est vide
 */
int isEmpty(queue_t * queue);

/*
 * Fonction pour verifier si la file est pleine
 */
int isFull(queue_t * queue);

/*
 * Fonction pour afficher une pile
 */
void printQueue(queue_t * queue);

#endif
