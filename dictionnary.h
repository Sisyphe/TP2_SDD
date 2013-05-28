/**
 * @file dictionnary.h
 *
 * @author Gerald lelong / Noel Martignoni
 * @date 2013-05-21
 *
 * @brief
 * Definit les fonctions en rapport avec les dictionnaires
*/

#ifndef DICTIONNARY_H
#define DICTIONNARY_H

#include "tree.h"

/**
 * @brief type representant un dictionnaire
 */
typedef node_t* Dict;

/**
 * @brief initialise un dictionnaire pret a etre utilise
 * @return le dictionnaire cree
 */
Dict createDict(char * string);

/**
 * @brief initialise un dictionnaire vide pret a etre utilise
 * @return le dictionnaire cree
 */
Dict createEmptyDict();

/**
 * @brief insere un mot dans un dictionnaire
 * @param dico le dictionnaire dans lequel inserer un mot
 * @param word le mot a inserer
 */
void insertWord(Dict * dico, char * word);

/**
 * @brief
 * @return
 */
int characterAreInferior(char one, char two);

/**
 * @brief
 * @return
 */
int characterAreSuperior(char one, char two);

/**
 * @brief affiche le contenu d'un dictionnaire dans l'ordre alphabetique
 * @param dict le dictionnaire a afficher
 */
void printDict(Dict dict);

/**
 * @brief libere la memoire allouee par le contenu d'un dictionnaire
 * @param dict le dictionnaire a supprimer
 */
void freeDict(Dict dict);

#endif