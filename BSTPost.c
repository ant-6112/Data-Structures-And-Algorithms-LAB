#include <stdio.h>
#include <stdlib.h>
 
struct BSTNode
{
    double data;
    struct BSTNode *left;
    struct BSTNode *right;
};

struct BSTNode* createNewNode(double V)
{
    struct BSTNode * newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->data = V;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

void inorder(struct BSTNode* root)
{
    if(root!=NULL){
        inorder(root->left); //L
        printf(" %5.2lf", root->data); // V
        inorder(root->right); //R
    }
}

struct BSTNode* constructBST(int postorder[], int start, int end)
{
    if (start > end) {
        return NULL;
    }
 
    // Construct the root node of the subtree formed by datas of the
    // postorder sequence in range `[start, end]`
    struct BSTNode* node = createNewNode(postorder[end]);
 
    // search the index of the last element in the current range of postorder
    // sequence, which is smaller than the root node's value
    int i;
    for (i = end; i >=start; i--)
    {
        if (postorder[i] < node->data) {
            break;
        }
    }
 
    // Build the right subtree before the left subtree since the values are
    // being read from the end of the postorder sequence.
 
    // recursively construct the right subtree
    node->right = constructBST(postorder, i + 1, end - 1);
 
    // recursively construct the left subtree
    node->left = constructBST(postorder, start, i);
 
    return node;
}
 
int main(void)
{
    /* Construct the following BST
              15
            /    \
           /      \
          10       20
         /  \     /  \
        /    \   /    \
       8     12 16    25
    */
 
    int postorder[] = { 8.0, 12.0, 10.0, 16.0, 25.0, 20.0, 15.0 };
    int n = sizeof(postorder)/sizeof(postorder[0]);
 
    struct BSTNode* root = constructBST(postorder, 0, n - 1);

    printf("Inorder traversal of BST is ");
 
    inorder(root);
 
    return 0;
}