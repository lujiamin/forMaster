#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    Node *right;
    Node *left;
}Node,*BSTree;
static int leaf_num = 0;

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

void create(BSTree &root,int elem[],int n){
    int i=0;
    while(i<n){
        insert(root,elem[i]);
        i++;
    }
}

void preOrder(BSTree &root){
    if(root){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(BSTree &root){
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void leafNum(BSTree &root){
    if(root->left == NULL && root->right == NULL){
        leaf_num ++;
    }
    if(root->left){
        leafNum(root->left);        
    }
    if(root->right){
        leafNum(root->right);
    }
}

int nodeNum(BSTree &root){
    if(root == NULL){
        return 0;
    }else
		return 1+nodeNum(root->left)+nodeNum(root->right);
}

int main(){
    BSTree root = NULL;
    int elem[] = {5,8,3,6,9,4,2,12};
    int n = 8;  
    create(root,elem,n);
    cout<<"create done\n";
    preOrder(root);
    cout<<"\n";
    inOrder(root);
    cout<<"\n";
    leafNum(root);
    cout<<leaf_num<<"\n";
    cout<<nodeNum(root)<<"\n";
    return 0;
}