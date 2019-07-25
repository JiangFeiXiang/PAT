//
// Created by JFX on 2019/7/19.
//
//平衡二叉树
#include <iostream>
#include <cmath>
using namespace std;
struct node{
    int v,height;
    node* left;
    node* right;
};
node* newNode(int x){
    node* Node=new node;
    Node->v=x;
    Node->height=1;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}
int getHeight(node* Node){
    if(Node==NULL) return 0;
    else return Node->height;
}
int getBalanceFactor(node* root){
    return getHeight(root->left)-getHeight(root->right);
}
void updateHeight(node* root){
    root->height=max(root->left->height,root->right->height)+1;
}
void search(node* root,int x){
    if(root==NULL){
        printf("Search failed\n");
        return;
    }
    if(root->v==x) printf("%d\n",root.v);
    else if(x<root->v) search(root->left,v);
    else search(root->right,x);
}
//左旋
void LeftRotation(node* &root){
    node* temp=root->right;
    root->right=temp->left;//将temp的左子树变为root的右子树，因为root的整个右子树都比root大
    temp->left=root;//将root变为temp的左子树
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
//右旋
void RightRotation(node* &root){
    node* temp=root->left;
    root->left=temp->right;
    temp->right=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}


