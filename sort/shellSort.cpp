#include <iostream>
using namespace std;

typedef int elemType;

void shell_sort(elemType arr[],int n){
    int dk,i,j; 
    // the length of step
    for(dk = n / 2;dk >= 1;dk = dk / 2){
        cout<<"dk:"<<dk<<endl;
        for(i = dk ;i < n;i++){
            if(arr[i] < arr[i-dk]){ 
                elemType tmp = arr[i];
                for(j = i-dk;j >= 0 && tmp < arr[j];j-=dk)
                    arr[j+dk] = arr[j];
                arr[j+dk] = tmp;
            }//end if
        }// end for

        for(int k = 0;k < n;k ++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }// end for
}

int main(int argc, char const *argv[]){
    elemType arr[] = {12,5,7,3,8,1,10,19,2,8};
    int n = 10;
    shell_sort(arr,n);
    cout<<"the arr after sorting:\n";
    for(int i = 0; i < n; i ++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}