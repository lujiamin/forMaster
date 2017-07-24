#include <iostream>
using namespace std;

void Reverse(int arr[],int from,int to){
    int i,temp;
    for(i=0;i<(to-from+1)/2;i++){
        temp = arr[from+i];
        arr[from+i] = arr[to-i];
        arr[to-i] = temp;
    }
}

void Conv(int arr[],int n,int p){
    Reverse(arr,0,p-1);
    Reverse(arr,p,n-1);
    Reverse(arr,0,n-1);
}

int main(int argc, char const *argv[]){
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = 8;
    int p = 3;
    Conv(arr,n,p);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}