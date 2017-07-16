#include <cstdio>
#include <cstdlib>
typedef int elemType;
// the single LinkedList
typedef struct LNode{
    elemType data;
    LNode *next;
}LNode, *LinkedList;

int getLength(LinkedList &L){
    LinkedList p;
    p = L->next;
    int len = 0;
    while(p){
        p = p->next;
        len++;
    }
    return len;
}

void init(LinkedList &L){
    // L:the head node
    L->next = NULL;
}

void insert(LinkedList &L,int i,elemType e){
    int j=0;
    LinkedList p;
    p = L;
    //find the location i-1
    while(p && j<i-1){
        p=p->next;
        j++;
    }
    LinkedList s = (LinkedList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
}

void insertBeforeHead(LinkedList &L,elemType e){
    LinkedList p = (LinkedList)malloc(sizeof(LNode));
    p->data = e;
    p->next = L->next;
    L->next = p;
}

void insertAfterEnd(LinkedList &L,elemType e){
    LinkedList p,s;
    p = L;
    //locate the end node
    while(p->next){
        p = p->next;
    }
    s = (LinkedList)malloc(sizeof(LNode));
    s->data = e;
    s->next = NULL;
    p->next = s;
}

// i means location
void del(LinkedList &L,int i){
    // check the location is error
    if(i < 1 || i > getLength(L)){
        return;
    }
    LinkedList p;
    p = L;
    int j=0;
    while(p && j < i-1){
        p = p->next;
        j++;
    }
    p->next = p->next->next;
}

void printLinkedList(LinkedList &L){
    LinkedList p = L->next;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[]){
    LinkedList L;
    init(L);
    insert(L,1,4);
    insert(L,1,3);
    insert(L,2,5);
    printLinkedList(L);
    printf("the length of the LinkedList is %d\n", getLength(L));
    del(L,3);
    printLinkedList(L);
    printf("the length of the LinkedList is %d\n", getLength(L));
    printf("%s\n", "insert 78 before head...");
    insertBeforeHead(L,78);
    printLinkedList(L);
    printf("the length of the LinkedList is %d\n", getLength(L));
    printf("%s\n", "insert 100 after end...");
    insertAfterEnd(L,100);
    printLinkedList(L);
    printf("the length of the LinkedList is %d\n", getLength(L));
    return 0;
}