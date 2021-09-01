#include<stdio.h>

struct BSTNode 
{
    double data;
    struct BSTNode* left;
    struct BSTNode* right;
};

//ROOT NODE
struct BSTNode* BSTree = NULL;

//createNewNode(v)
//addNode
//Transverals : Inorder - Postorder - Preorder
//Searching in BST
//Maximum Element
//Kth Maximum Element

struct BSTNode* createNewNode(double V)
{
    struct BSTNode * newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->data = V;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addNode(struct BSTNode* root , double V)
{
    if(root == NULL)
    {
        BSTree = createNewNode(V);
        return;
    }
    if(root->data == V)
    {
        return;
    }

    if(root->data > V)
    {
        if(root->left == NULL)
        {
            struct BSTNode* newNode = createNewNode(V);
            root->left = newNode;
        }else{
            addNode(root->left,V);
        }
    }else{
        if(root->right == NULL){
            struct BSTNode* newNode = createNewNode(V);
            root->left = newNode;
        }else{
            addNode(root->right , V);
        }
    }
}


// Printing  LVR
void inorder(struct BSTNode* root)
{
    if(root!=NULL){
        inorder(root->left); //L
        printf(" %5.2lf", root->data); // V
        inorder(root->right); //R
    }
}

// Printing VLR
void preorder(struct BSTNode* root)
{
    if(root!=NULL){
        printf(" %5.2lf", root->data); // V
        preorder(root->left); //L
        preorder(root->right); //R
    }
}

// Printing LRV
void postorder(struct BSTNode* root)
{
    if(root!=NULL){
        postorder(root->left); //L
        postorder(root->right); //R
        printf(" %5.2lf", root->data); // V
    } 
}

//0 : Key Is Not Present in the BST
//1 : Key Is Present in the BST

int Search(struct BSTNode* root, double Key)
{
    if(root == NULL){
        return 0;
    }
    if(root->data == Key){
        return 1;
    }else if(root->data > Key){
        return Search(root->left , Key);
    }else{
        return Search(root->right , Key);
    }
    //return 0;
}

double Minimum(struct BSTNode* root)
{
    if(root == NULL)
    {
        return INFINITY;
    }
    if(root->left == NULL)
    {
        return (root->data);
    }
    return Minimum(root->left);
}

double Maximum(struct BSTNode* root){
    if(root == NULL)
    {
        return (-1)*INFINITY;
    }
    if(root->right == NULL)
    {
        return (root->data);
    }
    return Maximum(root->right);
}

int main(void){

    
}




