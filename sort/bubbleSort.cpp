#include <iostream>
using namespace std;

typedef int elemType;

void bubble_sort(elemType arr[],int n){
    for(int i=0;i<n-1;i++){
        bool flag = false;
        for(int j=n-1;j>i;j--){
            if(arr[j]<arr[j-1]){
                elemType tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
                flag = true;
            }
        }
        // no swap,the array is in order
        if(!flag){
            return;
        }
        cout<<i<<". ";
        for(int i = 0;i < n;i ++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[]){
    elemType arr[] = {12,5,7,3,8,1,10,19,2,8};
    int n = 10;
    bubble_sort(arr,n);
    for(int i = 0; i < n; i ++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}