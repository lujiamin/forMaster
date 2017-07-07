#include<stdio.h>
#include<stack>
using namespace std;
//十进制转八进制
void conversion(){
	stack<int> mystack;
	unsigned n;
	printf("input n (n>0):");
	scanf("%u",&n);
	//将n模8的余数入栈，并令n=n/8
	while(n){
		mystack.push(n%8);
		n/=8;
	}
	//如果栈不为空，则出栈
	while(!mystack.empty()){
		printf("%d",mystack.top());
		mystack.pop();
	}
	printf("\n");
}
int main(){
	conversion();
	return 0;
}