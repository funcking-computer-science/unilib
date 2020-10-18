#include <binary_tree.h>

struct bnode
{
    struct bnode *parent;
    struct bnode *left;
    struct bnode *right;
    void *key;
};

struct bnode *create_bnode(void *k)
{
    if(k == NULL)
        return NULL;
    struct bnode *node = (struct bnode *) malloc(sizeof(struct bnode));
    node->parent = node->left = node->right = NULL;
    node->key = k;
    return node;
};


void insert_btree(struct bnode *root, struct bnode *node, comparer comp)
{  
    //if tree is empty initialize it with node
    if(root == NULL)
    {
        root = node;
        return;
    }

    //otherwise search the appropriate place
    if(comp(root->key, node->key) == B_TREE_GREATER)
    {
        printf("go to left tree with: [%d]\n", *((int *)(node->key)));
        insert_btree(root->left, node, comp);
    }
    else 
    {
        printf("go to right tree with: [%d]\n", *((int *)(node->key)));
        insert_btree(root->right, node, comp);
    }
}