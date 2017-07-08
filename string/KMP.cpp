#include<stdio.h>
//失败函数,next[]数组
void getNext(char T[],int next[],int len){	
	int i=0,k=-1;
	next[0]=-1;	
	
	while(i<len){
		if(k==-1||T[i]==T[k]){
			++k;
			++i;		
			next[i]=k;
		}else{
			k=next[k];
		}
	}
}

//改进的失败函数
void modifiedFail(char T[],int next[],int len){
	int i=0,k=-1;
	next[0]=-1;
	while(i<len){
		if(k==-1||(T[i]==T[k])){
			i++;
			k++;
			if(T[i]==T[k]){
				next[i]=next[k];
			}else{
				next[i]=k;
			}
		}else{
			k=next[k];
		}
	}
}
//定位模式串的位置
int indexOfString(char S[],int n,char T[],int m,int pos,int next[]){
	
	int i=pos;
	int j=0;
	
	while(i<n && j<m){
		if(j==-1||S[i]==T[j]){
			i++;
			j++;
		}else{
			j=next[j];
		}
	}
	
	return ((j==m)?i-m:-1);
}

void main(){
	char S[]="abcabcaabcabcabbac"; //len=18
	char T[]="abcabcabbac";  //len=11
	int i=0;
	//打印主串
	printf("string S:");
	for(i=0;i<18;i++){
		printf("%c",S[i]);
	}
	printf("\n");
	//打印模式串
	printf("string T:");
	for(i=0;i<11;i++){
		printf("%c",T[i]);
	}
	printf("\n");
	
	int next[11];
	getNext(T,next,11);
	//打印失败函数数组
	printf("the next array:");
	for(i=0;i<11;i++){
		printf("%d ",next[i]);
	}
	printf("\n");
	
	int next1[11];
	char T1[]="abcabcabbac";
	//打印改进后的失败函数数组
	printf("the modified next array:");
	modifiedFail(T1,next1,11);
	for(i=0;i<11;i++){
		printf("%d ",next1[i]);
	}
	printf("\n");
	
	//打印模式串在主串中的位置
	int pos = 0;
	char T2[]="abcabcabbac";
	int index = indexOfString(S,18,T2,11,pos,next);
	printf("the index is %d\n",index);
	return;
}