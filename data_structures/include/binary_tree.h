/*
 *
 *                      BINARY TREE 
 *      by Bastard, all right reserver (i'm actually joking)
 * 
*/
#ifndef UNILIB_BINARY_TREE_
    #define UNILIB_BINARY_TREE_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAST(R, TYPE) *((TYPE) R)
#define min_btree(R)            __return_element(__min_btree(R))
#define max_btree(R)            __return_element(__max_btree(R))
#define search_btree(R, K, C)   __return_element(__search_bnode(R, K, C))

struct bnode;
enum 
{
    BTREE_GREATER, 
    BTREE_LESS, 
    BTREE_EQUAL
};

typedef int(*comparer)(void *, void *);
void inorder_traversal(struct bnode *root);

/*
 * comparer is a pointer to a function 
 * which returns true if first argument 
 * is greater then second, and false otherwise
*/
void recursive_insert_btree(struct bnode **root, void *key, comparer comp);
void insert_btree(struct bnode **root, void *key, comparer comp);
void erase_btree(struct bnode **root, struct bnode *node);
static void __transplant_btree(struct bnode **root, struct bnode **unode, struct bnode **vnode);

//return pointer to create node
struct bnode *create_bnode(void *k);

//search the node by key
struct bnode *__search_bnode(struct bnode *root, void *k, comparer comp);

//return node which contain minimal element in tree
struct bnode *__min_btree(struct bnode *root);

//returns node which contain maximal element in tree 
struct bnode *__max_btree(struct bnode *root);

//just helper
void *__return_element(struct bnode *root);
#endif