#include <cstdio>
#define maxSize 50

typedef int elemType;
typedef struct{
    elemType data[maxSize];
    int front,rear;
}sqQueue;

// init
void init(sqQueue &q){
    q.rear = q.front = 0;
}

//
bool empty(sqQueue &q){
    if(q.rear == q.front){
        return true;
    }else
        return false;
}

//
bool full(sqQueue &q){
    if((q.rear+1) % maxSize == q.front){
        return true;
    }else{
        return false;
    }
}

bool enQueue(sqQueue &q, elemType x){
    // if full
    if(full(q)){
        return false;
    }
    q.data[q.rear] = x;
    // (rear+1) % maxSize
    q.rear = (q.rear + 1) % maxSize;
    return true;

}

bool deQueue(sqQueue &q, elemType &x){
    if(empty(q)){
        return false;
    }
    x = q.data[q.front];
    q.front = (q.front + 1) % maxSize;
    return true;
}

int main(int argc, char const *argv[]){
    sqQueue q;
    init(q);
    printf("empty:%d\n", empty(q));
    enQueue(q,1);
    enQueue(q,3);
    enQueue(q,2);
    enQueue(q,4);
    printf("after enQueue 1, 3, 2, 4:\n");
    printf("empty:%d\n", empty(q));
    int x;
    deQueue(q,x);
    printf("the deQueue of front:%d\n", x);
    return 0;
}