#include<stdio.h>
#include<stack>
using namespace std;
//¿®∫≈∆•≈‰µƒºÏ—È
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
			st.push(*p++);//»Î’ª
			break;
		case ']':
		case ')':
			if(!st.empty()){
				char e=st.top();
				st.pop();  // ”ˆµΩ”“¿®∫≈£¨µØ≥ˆ’ª∂•
				if((*p==')' && e!='(')||(*p==']' && e!='[')){
					printf("◊Û”“¿®∫≈≤ª∆•≈‰\n");
					exit(0);
				}else{
					p++;
					break;
				}
			}else{
				printf("»±∑¶◊Û¿®∫≈\n");
				exit(0);
			}
		default:
			p++;
		}
	}
	if(st.empty()){
		printf("it's ok.\n");
	}else{
		printf("»±∑¶”“¿®∫≈\n");
	}
}
void main(){
	check();
	return;
}