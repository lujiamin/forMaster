#include<stdio.h>

int c=0;//ȫ�ֱ������ᶯ����

//��n��Բ�̴�x�ᵽz
void move(char x,int n,char z){
	printf("%i.move disk %i from %c to %c \n",++c,n,x,z);
}

void hanoi(int n,char x,char y,char z){
	if(n==1){
		move(x,1,z);
	}else{
		hanoi(n-1,x,z,y);  /* ��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z�������� */
		move(x,n,z); /* �����Ϊn��Բ�̴�x�Ƶ�z */
		hanoi(n-1,y,x,z);/* ��y�ϱ��Ϊ1��n-1��Բ���Ƶ�z��x�������� */
	}
}
void main(){
	int n;
	printf("input the num of disk:");
	scanf("%d",&n);
	hanoi(n,'a','b','c');
	return;
}