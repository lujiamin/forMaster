#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    Node *right;
    Node *left;
}Node,*BSTree;

// 向二叉排序树中插入元素
int insert(BSTree &root,int e){    
    if(root == NULL){
        root = new Node;
        root->data = e;
        root->right = root->left = NULL;
        return 1;
    }
    else if(e == root->data){
        return 0;
    }
    else if(e < root->data){
        return insert(root->left,e);
    }
    else {
        return insert(root->right,e);
    }
}

// 创建二叉排序树
void create(BSTree &root,int elem[],int n){
    int i=0;
    while(i<n){
        insert(root,elem[i]);
        i++;
    }
}

// 先序遍历
void preOrder(BSTree &root){
    if(root){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

//中序遍历
void inOrder(BSTree &root){
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int main(){
    BSTree root = NULL;
    int elem[] = {5,8,3,6,9,4};
    int n = 6;
    create(root,elem,n);
    cout<<"create done\n先序遍历";
    preOrder(root);
    cout<<"\n中序遍历";
    inOrder(root);
    cout<<"\n";
    return 0;
}