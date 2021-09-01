#include<stdio.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};

struct Node* Bstree;

void Search(struct Node* root,int value){
    if(root == NULL){
        return;
    }else if(root->data == value){
        return;
    }else{
        if(root->data < value){
            return Search(root->left,value);
        }else{
            return Search(root->right,value);
        }
    }
}

void Search(struct Node* root,int value){
    if(root == NULL){
        return;
    }else{
        struct Node* i;
        for(i = root;i->left == NULL && i->right == NULL;){
            if(i->data == value){
                return;
            }else if(i->data > value){
                i = root->right;
            }else{
                i = root->left;
            }
        }
    }
}

int Min(struct Node* root){
    if(root == NULL){
        return;
    }else{
        int min = root->data;
        if(min < )
    }
}

int Max(struct Node* root){

}

int main(void){

}




