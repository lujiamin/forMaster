#include <iostream>
using namespace std;

// 图的临接矩阵实现闭包
int main(){
    int a[4][4]={{0,1,0,0},{0,0,0,1},{0,0,0,0},{1,0,1,0}};
    int temp[4][4]={0};
    int n = 4;
    int i,j,k;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                a[i][j] = a[i][j] ||(a[i][k] & a[k][j]);
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
