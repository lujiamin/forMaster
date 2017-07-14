#include <cstdio>
#include <cstdlib>

typedef int elemType;
// the node of binary search tree
typedef struct BinSearchNode{
	elemType data;
	BinSearchNode *lchild,*rchild;
}BinSearchNode, *BinSearchTree;

// init the binary tree
void InitTree(BinSearchTree &T){
	T = NULL;
}

// search the binary search
int Search(BinSearchTree &T,elemType e){
	if(!T){
		return 0;
	}
	// if equal ,return 1
	if(T->data == e){
		return 1;
	}else if(T->data > e){
		return Search(T->lchild,e);
	}else{
		return Search(T->rchild,e);
	}
}

//insert element into tree
int InsertBinSearchTree(BinSearchTree &T,elemType e){
	if(T == NULL){
		T = (BinSearchTree)malloc(sizeof(BinSearchNode));
		T->data = e;
		T->lchild = T->rchild = NULL;
		return 1;
	}else if(e == T->data){
		return 0;
	}else if(e < T->data){
		return InsertBinSearchTree(T->lchild, e);
	}else{
		return InsertBinSearchTree(T->rchild, e);
	}
}
// 
void InOrder(BinSearchTree &T){
	if(T){
		InOrder(T->lchild);
		printf("%d ", T->data);
		InOrder(T->rchild);
	}
}

//
int main(){
	BinSearchTree T;
	InitTree(T);
	InsertBinSearchTree(T,6);
	InsertBinSearchTree(T,2);
	InsertBinSearchTree(T,1);
	InsertBinSearchTree(T,4);
	InsertBinSearchTree(T,3);
	InsertBinSearchTree(T,8);
	InsertBinSearchTree(T,7);
	printf("%s\n", "binary tree created");
	printf("%s", "the InOrder of Binary Tree:");
	InOrder(T);
	printf("\n");
	elemType key = 4;
	if(Search(T,key)==0){
		printf("%d not exist.\n", key);
	}else{
		printf("%d exist.\n",key);
	}
	return 0;
}