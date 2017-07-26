#include <cstdio>
#include <cstdlib>

typedef int elemType;
typedef struct LNode{
    elemType data;
    LNode *next;
}LNode,*LinkedList;

void create(LinkedList &L){
    elemType x;
    L = (LinkedList)malloc(sizeof(LNode));
    LNode *s,*r=L;
    scanf("%d",&x);
    while(x!=-1){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
}

void print_list(LinkedList &L){
    LNode *s;
    s = L->next;
    while(s){
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}

// search one time
int search_last_k(LinkedList &L,int k){
    LNode *p = L->next,*q = L->next;
    int count = 0;
    while(p!=NULL){
        // printf("%d  %d\n", p->data,q->data);
        if(count < k){
            count++;
        }else{
            q = q->next;
        }
        p = p->next;
    }//end while
    if(count<k){
        return 0;
    }else{
        printf("the last %d element is:%d\n", k,q->data);
        return 1;
    }
}

int main(){
    LinkedList L;
    printf("input the list(end with -1):");
    create(L);
    printf("the list:\n");
    print_list(L);
    int k=4;
    printf("the result:%d\n",search_last_k(L,k));
    return 0;
}

