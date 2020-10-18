#ifndef UNILIB_BINARY_TREE_
    #define UNILIB_BINARY_TREE_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 *
 *      BINARY TREE IMPLEMENTATION
 * 
*/

enum
{
    B_TREE_EQUAL,
    B_TREE_GREATER,
    B_TREE_LESS
};

typedef int(*comparer)(void *, void *);
struct bnode;

struct bnode *create_bnode(void *k);

/*
 * comparer is a pointer to a function 
 * which returns true if first argument 
 * is greater then second, and  false otherwise
*/
void insert_btree(struct bnode *root, struct bnode *node, comparer comp);

#endif