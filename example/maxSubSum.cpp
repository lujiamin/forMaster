#include <iostream>
using namespace  std;

// 
void maxSubSum(int arr[],int len){
    int i;
    int curSum = 0,maxSum = 0;
    for(i=0;i<len;i++){
        curSum += arr[i];
        if(curSum > maxSum){
            maxSum = curSum;
        }
        if(curSum < 0){
            curSum = 0;
        } 
    }
    cout<<maxSum<<endl;
}

int main(int argc, char const *argv[]){
    int arr[] = {1,-2,3,10,-4,7,2,-5};
    int len = 8;
    maxSubSum(arr,len);
    return 0;
}