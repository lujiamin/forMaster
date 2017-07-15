#include <cstdio>
#include <cstdlib>

typedef int elemType;
// the node
typedef struct LinkedNode{
    elemType data;
    LinkedNode *next;  
}LinkedNode;

//the queue
typedef struct{
    LinkedNode *front,*rear;
}LinkedQueue;

void init(LinkedQueue &q){
    q.front = q.rear = (LinkedNode*)malloc(sizeof(LinkedNode));
    q.front->next = NULL;
}

bool empty(LinkedQueue &q){
    if(q.front == q.rear){
        return true;
    }else{
        return false;
    }
}

void enQueue(LinkedQueue &q,elemType e){
    LinkedNode *s = (LinkedNode *)malloc(sizeof(LinkedNode));
    s->data = e;
    s->next = NULL;
    q.rear->next = s;
    q.rear = s;
}

bool deQueue(LinkedQueue &q,elemType &x){
    if(empty(q)){
        return false;
    }
    LinkedNode *p;
    p = q.front->next;
    x = p->data;
    q.front->next = p->next;
    if(q.rear == p){
        q.rear = q.front;
    }
    free(p);
    return true;
}

int main(int argc, char const *argv[]){
    LinkedQueue q;
    init(q);
    printf("empty?:%d\n", empty(q));
    enQueue(q,2);
    enQueue(q,10);
    enQueue(q,11);
    printf("after enQueue 2, 10, 11:\n");
    printf("empty?:%d\n", empty(q));
    int x;
    deQueue(q,x);
    printf("the deQueue of front:%d\n", x);
    return 0;
}