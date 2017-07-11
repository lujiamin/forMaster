#include <stdio.h>
#include <stdlib.h>
#define TelemType char

//the node
typedef struct BiTNode
{
    TelemType data;
    BiTNode *lchild,*rchild;
	
}BiTNode,*BiTree;

//create by PreOrder
void CreateBiTreeByPreOrder(BiTree *T){
    TelemType ch;
    scanf("%c",&ch);
    if(ch == '#'){
        *T = NULL;
    }else{
        *T = (BiTree) malloc(sizeof(BiTNode));
        if(!*T){
            exit(0);
        }
        //input the sequence by PreOrder. '#' means null pointer  
        (*T)->data = ch;
        CreateBiTreeByPreOrder(&(*T)->lchild);
        CreateBiTreeByPreOrder(&(*T)->rchild);
    }
}

//PreOrder
void PreOrder(BiTree T){
    if(T == NULL)
        return;
    printf("%c ", T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

//InOrder
void InOrder(BiTree T){
    if(T == NULL)
        return;
    InOrder(T->lchild);
    printf("%c ", T->data);
    InOrder(T->rchild);
}

//PostOrder
void PostOrder(BiTree T){
    if(T == NULL)
        return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    printf("%c ",T->data);
}

//get height of the tree
int getHight(BiTree T){
    if(T == NULL){
        return 0;
    }
    int leftH = getHight(T->lchild);
    int rightH = getHight(T->rchild);
    return (leftH >= rightH) ? leftH+1 : rightH+1;
}
int main(){
    BiTree tree;
    printf("%s\n", "input the PreOrder of tree('#' means null pointer): ");
    CreateBiTreeByPreOrder(&tree);
    printf("%s", "the tree created.");
    printf("\n%s", "preorder:");
    PreOrder(tree);
    printf("\n%s", "inorder:");
    InOrder(tree);
    printf("\n%s", "postorder:");
    PostOrder(tree);
    printf("\n");
    printf("the hight of tree is:%d\n",getHight(tree));
    return 0;
}