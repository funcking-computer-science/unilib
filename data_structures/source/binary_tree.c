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
    static int counter = 0;
    if(k == NULL)
        return NULL;
    struct bnode *node = (struct bnode *) malloc(sizeof(struct bnode));
    node->parent = node->left = node->right = NULL;
    node->key = k;
    counter++;
    return node;
};

void insert_btree(struct bnode **root, void *key, comparer comp)
{  
    //if tree is empty do insert
    if(*root == NULL)
    {
        *root = create_bnode(key);
        return;
    }

    if(comp((*root)->key, key))
        insert_btree(&(*root)->left, key, comp);
    else 
        insert_btree(&(*root)->right, key, comp);
}

void inorder_traversal(struct bnode *root)
{
    if(root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d\n", CAST(root->key, int*));
        inorder_traversal(root->right);
    }
}