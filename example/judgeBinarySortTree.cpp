#include <iostream>
using namespace std;

// judge if a post order seq belongs to a BinarySortTree
bool verify(int *seq,int len){
    if(seq == NULL || len < 0)
        return false;
    int i = 0;
    int root = seq[len-1];
    for(;i<len-1;i++){
        if(seq[i]>root)
            break;
    }
    int j = i;
    for(;j<len-1;j++){
        if(seq[j] < root)
            return false;
    }
    // left child tree
    bool left = true;
    if(i > 0){
        left = verify(seq,i);
    }
    // right child tree
    bool right = true;
    if(i<len-1){
        right = verify(seq+i,len-i-1);
    }
    return (left && right);
}

int main(){
    int seq[]={1,4,7,6,3,13,14,10,8};
    int len=7;
    cout<<verify(seq,len)<<endl;
}