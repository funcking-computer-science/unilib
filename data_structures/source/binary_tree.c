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
}

void recursive_insert_btree(struct bnode **root, void *key, comparer comp)
{  
    //if tree is empty do insert
    if(*root == NULL)
    {
        *root = create_bnode(key);
        return;
    }

    if(comp((*root)->key, key) == BTREE_GREATER)
        insert_btree(&(*root)->left, key, comp);
    else 
        insert_btree(&(*root)->right, key, comp);
};

void insert_btree(struct bnode **root, void *key, comparer comp)
{
    struct bnode *m_root = *root;
    struct bnode *node = create_bnode(key);

    struct bnode *y = NULL;
    struct bnode *x = m_root;
    while(x != NULL)
    {
        y = x;
        if(comp(x->key, node->key) == BTREE_GREATER)
            x = x->left;
        else 
            x = x->right;
    }
    node->parent = y;
    if(y == NULL)
        *root = node;
    else if(comp(y->key, node->key) == BTREE_GREATER)
        y->left = node;
    else 
        y->right = node;
}

struct bnode *__search_bnode(struct bnode *root, void *k, comparer comp)
{
    if(root == NULL || comp(root->key, k) == BTREE_EQUAL)
        return root;
    if(comp(root->key, k) == BTREE_GREATER)
        return __search_bnode(root->left, k, comp);
    else 
        return __search_bnode(root->right, k, comp);
}

struct bnode *__min_btree(struct bnode *root)
{
    while(root->left)
        root = root->left;
    return root;
}

struct bnode *__max_btree(struct bnode *root)
{
    while(root->right)
        root = root->right;
    return root;
}

inline void *__return_element(struct bnode *node)
{
    return node == NULL ? NULL : node->key;
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