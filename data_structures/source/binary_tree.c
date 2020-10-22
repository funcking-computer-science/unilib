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
};

void erase_btree(struct bnode **root, struct bnode *node)
{
    if(node == NULL)
        return;
    //when left child node is NULL
    if(node->left == NULL)
        __transplant_btree(root, &node, &node->right);
    //when left child node is NOT NULL, but right child is NULL 
    else if(node->right == NULL)
        __transplant_btree(root, &node, &node->left);
    //when both left and right child node is NOT NULL
    else
    {
        struct bnode *y = __min_btree(node->right);
        if(y->parent != node)
        {
            __transplant_btree(root, &y, &y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        __transplant_btree(root, &node, &y);
        y->left = node->left;
        y->left->parent = y;
    }
};

void __transplant_btree(struct bnode **root, struct bnode **unode, struct bnode **vnode)
{
    if((*unode)->parent == NULL)
        *root = *vnode;
    else if((*unode) == (*unode)->parent->left)
        (*unode)->parent->left = *vnode;
    else 
        (*unode)->parent->right = *vnode;
    if(vnode != NULL)
        (*vnode)->parent = (*unode)->parent;
}

struct bnode *__search_bnode(struct bnode *root, void *k, comparer comp)
{
    if(root == NULL)
        return root;
    if(comp(root->key, k) == BTREE_EQUAL)
        return root;
    if(comp(root->key, k) == BTREE_GREATER)
        return __search_bnode(root->left, k, comp);
    else 
        return __search_bnode(root->right, k, comp);
};

struct bnode *__min_btree(struct bnode *root)
{
    while(root->left)
        root = root->left;
    return root;
};

struct bnode *__max_btree(struct bnode *root)
{
    while(root->right)
        root = root->right;
    return root;
};

inline void *__return_element(struct bnode *node)
{
    return node == NULL ? NULL : node->key;
};

void inorder_traversal(struct bnode *root)
{
    if(root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d\n", CAST(root->key, int*));
        inorder_traversal(root->right);
    }
};