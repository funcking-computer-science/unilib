#ifndef UNILIB_BINARY_TREE_
    #define UNILIB_BINARY_TREE_

/*
 *
 *      BINARY TREE IMPLEMENTATION
 * 
*/

struct binary_tree
{
    struct binary_tree *parent;
    struct binary_tree *left;
    struct binary_tree *right;
    void *key;
};

#endif