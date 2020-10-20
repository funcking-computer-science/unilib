#ifndef UNILIB_BINARY_TREE_
    #define UNILIB_BINARY_TREE_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAST(R, TYPE) *((TYPE) R)

/*
 *
 *      BINARY TREE IMPLEMENTATION
 *      by Bastard, all right reserver (i'm actually joking)
 * 
*/

typedef bool(*comparer)(void *, void *);

struct bnode *create_bnode(void *k);
void inorder_traversal(struct bnode *root);
void show_btree(struct bnode *root);

/*
 * comparer is a pointer to a function 
 * which returns true if first argument 
 * is greater then second, and false otherwise
*/
void insert_btree(struct bnode **root, void *key, comparer comp);
#endif