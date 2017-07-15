#include <cstdio>
#define maxSize 50

typedef int elemType;
//the element of stack
typedef struct{
    elemType data[maxSize];
    int top;
}seqStack;

//init
void init(seqStack &st){
    st.top = -1;
}

bool empty(seqStack &st){
    if(st.top == -1){
        return true;
    }else{
        return false;
    }
}

bool push(seqStack &st,elemType e){
    if(st.top == maxSize-1){
        return false;
    }else{
        st.data[++st.top] = e;
        return true;
    }
}

bool pop(seqStack &st,elemType &x){
    if(st.top == -1){
        return false;
    }else{
        x = st.data[st.top];
        st.top --;
        return true;
    }
} 

bool top(seqStack &st,elemType &x){
    if(st.top == -1){
        return false;
    }else{
        x = st.data[st.top];
        return true;
    }
}

int main(){
    seqStack st;
    elemType x;
    init(st);
    printf("1:empty,0:not empty:%d\n",empty(st));
    push(st,2);
    printf("1:empty,0:not empty:%d\n",empty(st));
    push(st,1);
    push(st,3);
    printf("%s\n", "after push 2, 1, 3");
    pop(st,x);
    printf("the element to pop:%d\n", x);
    top(st,x);
    printf("the top element:%d\n", x);
    return 0;
}