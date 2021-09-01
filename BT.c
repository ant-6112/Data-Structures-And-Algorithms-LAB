#include<stdio.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

struct Node* root;

int Height(struct Node* root){
    if(root == NULL){
        return 0;
    }else if(root->left == NULL && root->right == NULL){
        return 1;
    }else{
        int Left = Height(root->left)+1;
        int Right = Height(root->right)+1;
        if(Left > Right){
            return Left;
        }else{
            return Right;
        }
    }
}

int Leaf(struct Node* root){
    if(root == NULL){
        return 0;
    }else if(root->left == NULL && root->right == NULL){
        return 1;
    }else{
        int Left = Leaf(root->left)+1;
        int Right = Leaf(root->right)+1;
        return Left+Right;
    }
}

struct Node* root1;
struct Node* root2;
struct Node* rootB;

