#include <iostream>
using namespace std;

typedef int elemType;
void select_sort(elemType arr[],int n){
    for(int i = 0; i < n-1; i ++){
        int min = i;
        for(int j = i + 1; j < n; j ++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(i != min){
            elemType tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        } 
        cout<<i<<". ";
        for(int k = 0;k < n;k ++){
            cout<<arr[k]<<" ";
        } 
        cout<<endl;  
    }
}

int main(int argc, char const *argv[]){
    elemType arr[] = {12,5,7,3,8,1,10,19,2,8};
    int n = 10;
    select_sort(arr,n);
    for(int i = 0; i < n; i ++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
