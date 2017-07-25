#include <iostream>
using namespace std;

// O(n)
int majority(int A[],int n){
    int i,c,count = 1;
    c = A[0];
    for(i=1;i<n;i++){
        if(A[i] == c){
            count++;
        }else{
            if(count > 0){
                count--;
            }else{
                c = A[i];
                count = 1;
            }
        }
    }// end for
    if(count > 0){
        for(i=count=0;i<n;i++){
            if(A[i] == c){
                count++;
            }
        }
    }
    if(count > n/2){
        return c;
    }else{
        return -1;
    }
}

int main(int argc, char const *argv[]){
    int A[] = {0,5,5,3,5,7,5,1};
    int n=8;
    cout<<majority(A,n);
    cout<<endl;;
    return 0;
}