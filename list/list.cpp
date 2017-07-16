#include <cstdio>
#define maxSize 50

typedef int elemType;
typedef struct{
    elemType data[maxSize];
    int length; // the current length
}seqList;

void init(seqList &l){
    l.length = 0;
}

bool insert(seqList &l,int i,elemType e){
    if(i < 1 || i > l.length + 1){
        return false;
    }
    if(l.length >= maxSize){
        return false;
    }
    for(int j = l.length;j >= i;j--){
        //array: 0~j-1,but list:1~j
        l.data[j] = l.data[j-1];
    }
    l.data[i-1] = e;
    l.length++;
    return true;
}

bool del(seqList &l,int i){
    if(i<1||i>l.length-1){
        return false;
    }
    for(int j=i;j<l.length;j++){
        l.data[j-1]=l.data[j];
    }
    l.length--;
    return true;
}

int locate(seqList &l,elemType e){
    int i;
    for(i=0;i<l.length;i++){
        if(l.data[i]==e){
            return i+1;
        }
    }
    return 0;//not exist;
}

void printList(seqList &l){
    for(int i=0;i<l.length;i++){
        printf("%d ", l.data[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[]){
    seqList l;
    init(l);
    insert(l,1,2);
    insert(l,1,3);
    insert(l,2,5);
    insert(l,2,10);
    printList(l);
    printf("the length is %d\n", l.length);
    printf("the locate of 5 is %d\n",locate(l,5));
    del(l,2);
    printList(l);
    printf("the length is %d\n", l.length);
    printf("the locate of 5 is %d\n",locate(l,5));
    return 0;
}
