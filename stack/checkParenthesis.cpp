#include<stdio.h>
#include<stack>
using namespace std;
//����ƥ��ļ���
void check(){
	stack<char> st;
	char ch[80],*p;
	printf("input the expression:");
	gets(ch);
	p=ch;
	while(*p){
		switch(*p){
		case '[':
		case '(':
			st.push(*p++);//��ջ
			break;
		case ']':
		case ')':
			if(!st.empty()){
				char e=st.top();
				st.pop();  // ���������ţ�����ջ��
				if((*p==')' && e!='(')||(*p==']' && e!='[')){
					printf("�������Ų�ƥ��\n");
					exit(0);
				}else{
					p++;
					break;
				}
			}else{
				printf("ȱ��������\n");
				exit(0);
			}
		default:
			p++;
		}
	}
	if(st.empty()){
		printf("it's ok.\n");
	}else{
		printf("ȱ��������\n");
	}
}
void main(){
	check();
	return;
}