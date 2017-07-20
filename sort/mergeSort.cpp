#include <iostream>
#include <cstdlib>
using namespace std;

typedef int elemType;

elemType *B = (elemType *)malloc(10*sizeof(elemType));

void merge(elemType arr[],int low,int mid,int high){
    int i,j,k;
     
    for(k = low;k <= high;k ++){
        B[k] = arr[k];
    }
    for(i=low,j=mid+1,k=i;i <= mid && j <= high;k++){
        // copy the less into arr
        if(B[i]<B[j])
            arr[k] = B[i++];
        else
            arr[k] = B[j++];
    }
    // if element left in a seq,copy into arr
    while(i<=mid){
        arr[k++] = B[i++];
    }
    while(j<=high){
        arr[k++] = B[j++];
    }

    // for(i = low; i <= high; i ++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
}

void merge_sort(elemType arr[],int low,int high){
    if(low < high){
        int mid = (low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(int argc, char const *argv[]){
    elemType arr[] = {12,5,7,3,8,1,10,19,2,8};
    int n = 10;
    merge_sort(arr,0,n-1);
    cout<<"the arr after sorting:\n";
    for(int i = 0; i < n; i ++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}