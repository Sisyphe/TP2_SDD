/**
 * @author Gerald Lelong / Noel Martignoni
 * @date 2013-04-16
 *
 * @file tree.c
 * @brief fichier d'entete de gestion des arbres
 *
 */

#ifndef TREE_H
#define TREE_H

/**
 * @typedef Element de l'arbre
 */
typedef char tree_item_t;

/**
 * @brief Structure de donnee representant un noeud d'un l'arbre
 */
typedef struct node
{
    tree_item_t item;
    struct node * sibling;
    struct node * child;
} node_t;

/**
 * @brief construit un arbre a partir d'une chaine
 * @return 
 */
void buildTree();

/**
 * @brief 
 * @return 
 */
int isOpenedParanthese(char car);

/**
 * @brief 
 * @return 
 */
int isClosedParanthese(char car);

/**
 * @brief 
 * @return 
 */
int isComma(char car);

/**
 * @brief 
 * @return 
 */
void insertWord(char * word);

/**
 * @brief Initialise une structure de noeud.
 * @return le noeud cree
 */
node_t * createNode();

/**
 * @brief Cree un noeud et l'initialise avec la donnee 'item'
 * @param item la donnee que le noeud doit contenir
 * @return le noeud cree et initiliase
 */
node_t * initNode(tree_item_t item);

/**
 * @brief Ajoute un fils 'item' au noeud 'Node'.
 * @param node le noeud auquel on veut ajouter un fils
 * @param item l'objet à ajouter à l'arbre
 * @return un code d'erreur de type errorCst
 */
int addChild(node_t * node, tree_item_t item);

int addSibling(node_t * node, tree_item_t item);

void printTree(node_t * node);

#endif
