#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
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

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

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

BSTNode* __bst__search_parent(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key && root->left != NULL)
        {
            if (value == root->left->key)
                return root;
                
            root = root->left;
        }
        else if (value > root->key && root->right != NULL)
        {
            if (value == root->right->key)
                return root;
                
            root = root->right;
        }
        else
        {
            return root;
        }
    }
    return root;
}

BSTNode* __bst__search_child1(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
        {
            if (root->left != NULL)
                root = root->left;
            return root;
        }
    }
    return root;
}

BSTNode* __bst__search_child2(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
        {
            if (root->right != NULL)
                root = root->right;
            return root;
        }
    }
    return root;
}

void bst_find2(BST *bst, int value) {
    BSTNode *temp1 = __bst__search_parent(bst->_root, value);
    BSTNode *temp2 = __bst__search_child1(bst->_root, value);
    BSTNode *temp3 = __bst__search_child2(bst->_root, value);
    
    if (temp1 == NULL || !bst_find(bst, value))
        printf("404 Not Found");
    else if (temp1->key == value)
        printf("-1 ");
    else
        printf("%d ", temp1->key);
        
    if (temp2 == NULL)
        printf("");
    else if (temp2->key != value && temp2 != NULL)
        printf("%d ", temp2->key);
    
         
    if (temp3 == NULL)
        printf("");
    else if (temp3->key != value && temp3 != NULL)
        printf("%d ", temp3->key);
    
        
    puts("");
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

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
    bst_init(&set);

    int N, M, i;
    scanf("%d", &N);
    int nilai_node[N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &nilai_node[i]);
        bst_insert(&set, nilai_node[i]);
    }
    scanf("%d", &M);
    int cari_node[M];
    for(i = 0; i < M; i++)
    {
        scanf("%d", &cari_node[i]);
        bst_find2(&set, cari_node[i]);
    }
    
    puts("");
    
    return 0;
}