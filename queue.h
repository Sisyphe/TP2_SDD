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

/**
 * @brief typedef Structure de la file
 */
typedef struct
{
	queueItem_t * items;
	unsigned int size;
	unsigned int indexStart;
	unsigned int indexEnd;
    unsigned int nbElement;
} queue_t;

/**
 * @brief Fonction de creation de file
 */
queue_t * createQueue(int size);

/**
 * @brief Fonction pour emfiler un element
 */
int pushQueue(queue_t * queue, queueItem_t item);

/**
 * @brief Fonction pour defiler un element
 */
queueItem_t * popQueue(queue_t * queue);

/**
 * @brief Fonction pour verifier si la file est vide
 */
int isQueueEmpty(queue_t * queue);

/**
 * @brief Fonction pour verifier si la file est pleine
 */
int isQueueFull(queue_t * queue);

/**
 * @brief Fonction pour afficher une pile
 */
void printQueue(queue_t * queue);

/**
 * @brief Libere la mémoire allouee lors de la creation de la file
 * @param queue La file a supprimer
 */
void freeQueue(queue_t * queue);

#endif
