#include <iostream>
using namespace std;

// O(n)
int getMiddle(int s1[],int s2[],int len){
    int i=0,j=0;
    while(len--){
        // cout<<"len: "<<len<<" i:"<<i<<" "<<s1[i]<<" j:"<<j<<" "<<s2[j]<<endl;
        if(len == 0){
            if(s1[i] > s2[j]){
                return s2[j];
            }else{
                return s1[i];
            }
        }
        if(s1[i] > s2[j]){
            j++;
        }else{
            i++;
        }
    }
}

// O(log2(n))
int Middle_search(int s1[],int s2[],int len){
    int begin1 = 0,begin2 = 0,mid1,mid2,end1 = len-1,end2 = len - 1;
    while(begin1 != end1 || begin2 != end2){
        mid1 = (begin1 + end1)/2;
        mid2 = (begin2 + end2)/2;
        cout<<"s1[begin]:"<<s1[begin1]<<"\ts1[mid]:"<<s1[mid1]<<"\ts1[end]:"<<s1[end1]<<endl;
        cout<<"s2[begin]:"<<s2[begin2]<<"\ts2[mid]:"<<s2[mid2]<<"\ts2[end]:"<<s2[end2]<<endl;
        cout<<"******************************************"<<endl;
        if(s1[mid1] == s2[mid2]){
            return s1[mid1];
        }
        if(s1[mid1] < s2[mid2]){
            if((begin1 + end1) % 2 == 0){
                begin1 = mid1;
                end2 = mid2;
            }else{
                begin1 = mid1 + 1;
                end2 = mid2;
            }
        }else{
            if((begin2 + end2) % 2 == 0){
                end1 = mid1;
                begin2 = mid2;
            }else{
                end1 = mid1;
                begin2 = mid2 + 1;
            }

        }
    }// end while
    return s1[begin1] < s2[begin2] ? s1[begin1] : s2[begin2];
}

int main(int argc, char const *argv[]){
    int s1[] = {11,13,15,17,19};
    int s2[] = {2,4,6,8,20};
    int len = 5;
    cout<<"the middle:"<<endl;
    cout<<getMiddle(s1,s2,len);
    cout<<endl;
    cout<<Middle_search(s1,s2,len);
    cout<<endl;
    return 0;
}