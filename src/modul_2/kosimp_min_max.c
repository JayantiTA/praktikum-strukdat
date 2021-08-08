#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int level_maximum[522];
int level_minimum[522];
int curr_level = 0;
int level_max = 0;

typedef struct bstnode_t {
    int key;
    struct bstnode_t 
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;

    if (value < level_minimum[curr_level])
        level_minimum[curr_level] = value;
    if (value > level_maximum[curr_level])
        level_maximum[curr_level] = value;

    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key) 
    {
        curr_level++;
        if (level_max < curr_level)
            level_max = curr_level;
        root->left = __bst__insert(root->left, value);
    }
    else if (value > root->key)
    {
        curr_level++;
        if (level_max < curr_level)
            level_max = curr_level;
        root->right = __bst__insert(root->right, value);
    }
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

int main()
{
    BST set;

    int N, j;
    int *A;
    
    bst_init(&set);

    memset(level_minimum, 1000000, sizeof(level_minimum));

    scanf("%d", &N);
    A = (int*) malloc((N+10) * sizeof(int));
    for (j = 0; j < N; j++)
    {
        scanf("%d", &A[j]);
        curr_level = 0;
        bst_insert(&set, A[j]);
    }

    if (level_max % 2 == 0)
    {
        for (j = level_max; j >= 0; j--)
        {
            if (j % 2 == 1)
                printf("%d ", level_maximum[j]);
            else   
                printf("%d ", level_minimum[j]);
        }
    }
    else
    {
        for (j = level_max; j >= 0; j--)
        {
            if (j % 2 == 0)
                printf("%d ", level_maximum[j]);
            else   
                printf("%d ", level_minimum[j]);
        }
    }
    
    puts("");
    
    return 0;
}