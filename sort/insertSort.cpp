#include <iostream>
using namespace std;

typedef int elemType;

void insert_sort(elemType arr[],int n){
    int i,j;
    elemType tmp;
    for(i = 1;i < n;i ++){
        tmp = arr[i];
        for(j = i-1;tmp < arr[j] && j>=0;j--){
            arr[j+1] = arr[j]; 
        }
        arr[j+1] = tmp;
        cout<<i<<". ";
        for(int k = 0; k < n; k ++){
           cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[]){
    elemType arr[] = {12,5,7,3,8,1,10,19,2,8};
    int n = 10;
    insert_sort(arr,n);
    for(int i = 0; i < n; i ++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}