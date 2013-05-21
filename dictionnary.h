#ifndef DICTIONNARY_H
#define DICTIONNARY_H

#include "tree.h"

/**
 * @brief
 */
typedef node_t* Dict;

/**
 * @brief
 * @return
 */
Dict createDict();

/**
 * @brief
 * @return
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
 * @brief
 * @return
 */
void printDict(Dict dict);

#endif