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
 * @param treeString la chaine representant l'arbre
 * @return l'arbre cree a partir la chaine
 */
node_t * buildTree(char * treeString);

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
 * @return le noeud cree
 */
node_t* addChild(node_t * node, tree_item_t item);

/**
 * @brief Ajoute un frere 'item' au noeud 'Node'.
 * @param node le noeud auquel on veut ajouter un frere
 * @param item l'objet à ajouter à l'arbre
 * @return le noeud cree
 */
node_t* addSibling(node_t * node, tree_item_t item);

/**
 * @brief Affiche le contenu de l'arbre sous le noeud 'node'
 * @param node le noeud à partir duquel on veut afficher l'arbre
 */
void printTree(node_t * node);

#endif
