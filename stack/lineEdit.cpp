#include<stdio.h>
#include<stack>
using namespace std;
FILE *fp;
//�б༭����
void LineEdit(){
	stack<char> st;
	char ch;
	ch=getchar();
	// EOF ��Ӧ����ctrl+z
	while(ch!=EOF){
		while(ch!=EOF&&ch!='\n'){
			switch(ch){
			case '#'://����'#',ɾ��ջ��
				st.pop();
				break;
			case '@'://����'@',���ջ
				while(!st.empty()){
					st.pop();
				}
				break;
			default:
				st.push(ch);
			}
			ch=getchar();
		}
		stack<char>tmp;//��ʱջ�����ڽ�ԭջst�е�Ԫ�ش�ջ���������
		while(!st.empty()){
			tmp.push(st.top());
			st.pop();
		}
		while(!tmp.empty()){
			fputc(tmp.top(),fp);//����ʱջ�е�Ԫ��д���ļ�
			tmp.pop();
		}
		fputc('\n',fp);
		if(ch!=EOF){
			ch=getchar();
		}
	}
	while(!st.empty()){
		st.pop();
	}
}
void main(){
	fp=fopen("ed.txt","w");//����ed.txt�ļ���д��
	LineEdit();
	return;
}