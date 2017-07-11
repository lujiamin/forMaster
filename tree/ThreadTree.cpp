#include <cstdio>
#include <cstdlib>
using namespace std;

typedef char elemType;
typedef enum{
    Link,
    Thread
}PointerTag;
typedef struct BiThreadNode{
    elemType data;
    BiThreadNode *lchild,*rchild;
    PointerTag lTag;   //left and right tag
    PointerTag rTag; 
}BiThreadNode, *BiThreadTree;

BiThreadTree preNode;//point the node that been visited just now

//create BiThreadTree
void CreateBiThreadTree(BiThreadTree *T){
    elemType ch;
    scanf("%c",&ch);
    //printf("%c\n", ch);
    if(ch == '#'){
        *T = NULL;
    }else{
        *T = (BiThreadTree) malloc(sizeof(BiThreadNode));
        if(!*T){
            exit(0);
        }
        //input the sequence by PreOrder. '#' means null pointer  
        (*T)->data = ch;
        // (*T)->lTag = Link;
        // (*T)->rTag = Link;
        CreateBiThreadTree(&(*T)->lchild);
        CreateBiThreadTree(&(*T)->rchild);
    }
    //printf("end\n");
}

//threading tree with InOrder
void InOrderThreading(BiThreadTree T){
    //printf("threading");
    if(T){
        InOrderThreading(T->lchild);  //recur threading left child
        if(!T->lchild){   //no lchild
            T->lTag = Thread;
            T->lchild = preNode;  //left pointer points the pre node
        }
        if(!preNode->rchild) { //pre node has no rchild
            preNode->rTag = Thread;
            preNode->rchild = T;
        }
        preNode = T;
        InOrderThreading(T->rchild); //recur threading right child
    }
}

//get the head node of the link sequence
void getHeadNode(BiThreadTree *head, BiThreadTree tree){
    (*head) = (BiThreadTree)malloc(sizeof(BiThreadNode));
    if(*head == NULL){
        return;
    }
    (*head)->rchild = *head;
    (*head)->rTag = Link;

    if(!tree){
        (*head)->lchild = *head;
        (*head)->lTag = Link;
    }else{
        preNode = *head;
        (*head)->lchild = tree;
        (*head)->lTag = Link;
        InOrderThreading(tree);
        preNode->rchild = *head;
        preNode->rTag = Thread;
        (*head)->rchild = preNode;
    }
}

//
void InOrder(BiThreadTree T){  // T point the head node
    BiThreadTree p;
    p = T->lchild;
    while(p != T){
        while(p->lTag == Link){
            p = p->lchild;
        }
        printf("%c(lTag,rTag):%d,%d \n", p->data,p->lTag,p->rTag);
        while(p->rTag == Thread && p->rchild != T){
            p = p->rchild;
            printf("%c(lTag,rTag):%d,%d\n", p->data,p->lTag,p->rTag);
        }
        p = p->rchild;
    }
}
int main(int argc, char const *argv[]){
    BiThreadTree tree,head;
    printf("%s\n", "input the PreOrder of tree('#' means null pointer): ");
    CreateBiThreadTree(&tree);
    printf("create done\n");
    getHeadNode(&head,tree);
    printf("the lchild of head is(the root of tree):%c\n", head->lchild->data);
    printf("the rchild of head is(the end node of inorder sequence):%c\n", head->rchild->data);
    printf("the InOrder('0' means Link,'1' means Thread):\n");
    InOrder(head);
    printf("\n");
    return 0;
}