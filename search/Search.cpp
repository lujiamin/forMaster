#include <cstdio>
#include <cstdlib>
#define maxSize 50

typedef int elemType;
typedef struct{
    elemType *elem;
    int length;
}seqTable;

void init(seqTable &s){
    s.elem = (elemType*)malloc(maxSize*sizeof(elemType));
    s.length = 0;
}

void insert(seqTable &s,int i,elemType e){
    for(int j=s.length;j>=i;j--){
        s.elem[j+1]=s.elem[j];
    }
    s.elem[i] = e;
    s.length++;
}

int seq_search(seqTable &s,elemType e){
    int i=0;
    s.elem[0] = e;
    for(i=s.length;s.elem[i]!=e;i--);
    // if exist,return location. if not exist,return 0
    return i;
}

// the seq must be Asc order
int binary_search(seqTable &s,elemType e){
    int low = 1;
    int high = s.length;
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(s.elem[mid] == e){
            return mid;
        }else if(s.elem[mid] < e){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}

int print_seq(seqTable &s){
    for(int i=1;i<=s.length;i++){
        printf("%d ", s.elem[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]){
    seqTable s;
    init(s);
    insert(s,1,6);
    insert(s,1,5);
    insert(s,1,4);
    insert(s,1,2);
    insert(s,1,1);    
    print_seq(s);
    printf("the location of 6 is(seq_search):%d\n", seq_search(s,6));
    printf("the location of 6 is(binary_search):%d\n", binary_search(s,6));
    return 0;
}