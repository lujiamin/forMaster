#include<stdio.h>
#include<stack>
using namespace std;
//ʮ����ת�˽���
void conversion(){
	stack<int> mystack;
	unsigned n;
	printf("input n (n>0):");
	scanf("%u",&n);
	//��nģ8��������ջ������n=n/8
	while(n){
		mystack.push(n%8);
		n/=8;
	}
	//���ջ��Ϊ�գ����ջ
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