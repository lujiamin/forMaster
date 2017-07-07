#include<stdio.h>
#include<stack>
using namespace std;
FILE *fp;
//行编辑程序
void LineEdit(){
	stack<char> st;
	char ch;
	ch=getchar();
	// EOF 对应键盘ctrl+z
	while(ch!=EOF){
		while(ch!=EOF&&ch!='\n'){
			switch(ch){
			case '#'://遇到'#',删除栈顶
				st.pop();
				break;
			case '@'://遇到'@',清空栈
				while(!st.empty()){
					st.pop();
				}
				break;
			default:
				st.push(ch);
			}
			ch=getchar();
		}
		stack<char>tmp;//临时栈，用于将原栈st中的元素从栈底依次输出
		while(!st.empty()){
			tmp.push(st.top());
			st.pop();
		}
		while(!tmp.empty()){
			fputc(tmp.top(),fp);//将临时栈中的元素写入文件
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
	fp=fopen("ed.txt","w");//创建ed.txt文件并写入
	LineEdit();
	return;
}