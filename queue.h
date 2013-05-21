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

#include "tree.h"

/*
 * @typedef Element de la file
 */
typedef node_t* queueItem_t;

/*
 * @typedef Structure de la file
 */
typedef struct
{
	queueItem_t * items;
	unsigned int size;
	unsigned int indexStart;
	unsigned int indexEnd;
    unsigned int nbElement;
} queue_t;

/*
 * Fonction de creation de file
 */
queue_t * createQueue(int size);

/*
 * Fonction pour emfiler un element
 */
int pushQueue(queue_t * queue, queueItem_t item);

/*
 * Fonction pour defiler un element
 */
queueItem_t * popQueue(queue_t * queue);

/*
 * Fonction pour verifier si la file est vide
 */
int isQueueEmpty(queue_t * queue);

/*
 * Fonction pour verifier si la file est pleine
 */
int isQueueFull(queue_t * queue);

/*
 * Fonction pour afficher une pile
 */
void printQueue(queue_t * queue);

#endif
