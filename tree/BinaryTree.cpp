#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;
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

//LevelOrder,use queue to save each node
void LevelOrder(BiTree T){
    queue<BiTree> q;
    if(T != NULL){
        q.push(T);
    }
    BiTree b;
    while(!q.empty()){
        b = q.front();//get the front of queue
        printf("%c ", b->data);
        q.pop();//pop the front 
        if(b->lchild)
            q.push(b->lchild);
        if(b->rchild)
            q.push(b->rchild);
    }
}

//LevelOrder2,use vector
void LevelOrder2(BiTree T){
    std::vector<BiTNode *> v;
    v.push_back(T);
    int cur = 0;//means the current node
    int end = 1;//means the next node of end node (+1)
    while(cur < v.size()){
        end = v.size();
        while(cur < end){
            printf("%c ", v[cur]->data);
            if(v[cur]->lchild)
                v.push_back(v[cur]->lchild);
            if(v[cur]->rchild)
                v.push_back(v[cur]->rchild);
            cur ++;
        }
    }
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
    /*
    test tree : AB#EJ###C#G##
    */
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
    printf("\nthe hight of tree is:%d\n",getHight(tree));
    printf("%s", "LevelOrder(use queue):");
    LevelOrder(tree);
    printf("\nLevelOrder(use vector):");
    LevelOrder2(tree);
    printf("\n");
    return 0;
}