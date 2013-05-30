/**
 * @file stack.h
 *
 * @author Gerald lelong / Noel Martignoni
 * @date 2013-04-16
 *
 * @brief
 * Definit les fonctions de base de manipulation
 * des piles.
*/

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "tree.h"
#include "tools.h"

/**
 * @brief Definit le type d'element que la pile doit stocker.
 */
typedef int stack_item_t;

/**
 * @brief
 * La structure de pile manipulee
 */
typedef struct
{
    stack_item_t * head; /*!< Pointeur sur le premier element de la liste contigue de donnees */
    size_t capacity;  /*!< Le nombre maximum d'elements que peut contenir la pile */
    int topIndex; /*!< Indice du dernier element dans la liste contigue (ou -1 si la liste est vide) */
} stack_t;

/**
 * @brief Alloue une liste contigue et initialise les attributs d'une nouvelle pile.
 * @param capacity La taille de la liste contigue allouee donc le nombre maximum d'objets que peut contenir la pile
 * @return Un pointeur vers la structure de pile creee
 */
stack_t * createStack(size_t capacity);

/**
 * @param stack La pile sur laquelle on s'interroge
 * @return Un booleen valant vrai si la pile est vide, faux sinon
 */
int isStackEmpty(stack_t stack);

/**
 * @param stack La pile sur laquelle on s'interroge
 * @return Un booleen valant vrai si la pile est pleine, faux sinon
 */
int isStackFull(stack_t stack);

/**
 * @brief Retourne et supprime de la pile l'element en haut du tas.
 * @param stack La pile ou recuperer et supprimer l'element
 * @return L'element en haut de la pile
 */
stack_item_t * popStack(stack_t * stack);

/**
 * @brief Pose un element en haut de la pile
 * @param stack La pile ou ajouter l'element
 * @param item L'element a inserer
 * @return Un code d'erreur valant SUCCESS si l'element a bien ete insere, FAIL sinon
 */
int pushStack(stack_t * stack, stack_item_t item);

/**
 * @brief Affiche la taille, la capacite, et le contenu de la pile sur la sortie standard.
 * @details Le type d'objet contenu dans la pile doit necessairement être 'int'.
 * @param stack La pile a afficher
 */
void printStack(stack_t stack);

/**
 * @brief Libere la mémoire allouee lors de la creation de la pile
 * @param stack La pile a supprimer
 */
void freeStack(stack_t * stack);

#endif
