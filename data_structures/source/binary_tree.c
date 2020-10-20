#include <binary_tree.h>

struct bnode *create_bnode(void *k)
{
    static int counter = 0;
    if(k == NULL)
        return NULL;
    struct bnode *node = (struct bnode *) malloc(sizeof(struct bnode));
    node->parent = node->left = node->right = NULL;
    node->key = k;
    counter++;
    printf("%d bnode is created with:\n\tNODE ADDRESS: [%d]\n\tDATA ADDRESS: [%d]\n", counter, node, k);
    return node;
};

void show_btree(struct bnode *root)
{
    if(root == NULL)
    {
        printf("BINARY TREE IS EMPTY\n");
        return;
    }

    printf("root %d\n", CAST(root->key, int *));
    if(root->left != NULL)
        printf("\troot->left [%d]\n", CAST(root->left->key, int *));
    else 
        printf("\troot->left [NULL]\n");
    if(root->right != NULL)
        printf("\troot->right [%d]\n", CAST(root->right->key, int *));
    else 
        printf("\troot->right [NULL]\n");
    // printf("root->left%d\n", CAST(root->right->key, int *));
}

void insert_btree(struct bnode *root, void *key, comparer comp)
{  
    //if tree is empty do insert
    if(root == NULL)
    {
        printf("set new node with %d\n", CAST(key, int *));
        printf("ROOT ADDRESS BEFORE: [%d]\n", root);
        root = create_bnode(key);
        printf("ROOT ADDRESS AFTER: [%d]\n", root);
        return;
    }

    if(comp(root->key, key) == true)
    {
        printf("going with %d in left tree\n", CAST(key, int *));
        insert_btree(root->left, key, comp);
    }
    else 
    {
        printf("going with %d in right tree\n", CAST(key, int *));
        insert_btree(root->right, key, comp);
    }

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