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
 
// Recursive Function To Build a BST from a Preorder Sequence.
struct BSTNode* constructBST(int preorder[], int start, int end)
{
    if (start > end) {
        return NULL;
    }
 
    // Construct the Root Node of the Subtree Formed by Data of the
    // Preorder Sequence in Range `[start, end]`
    struct BSTNode* node = createNewNode(preorder[start]);
 
    // Search the index of the first element in the current range of preorder
    // Sequence larger than the root node's value
    int i;
    for (i = start; i <= end; i++)
    {
        if (preorder[i] > node->data){
            break;
        }
    }
 
    // Recursively Construct the Left Subtree
    node->left = constructBST(preorder, start + 1, i - 1);
 
    // Recursively Construct the Right Subtree
    node->right = constructBST(preorder, i, end);

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
 
    int preorder[] = { 15.0, 10.0, 8.0, 12.0, 20.0, 16.0, 25.0 };
    int n = sizeof(preorder)/sizeof(preorder[0]);
 
    struct BSTNode* root = constructBST(preorder, 0, n - 1);

    printf("Inorder traversal of BST is ");
    inorder(root);
 
    return 0;
}