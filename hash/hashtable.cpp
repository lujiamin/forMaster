#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1
#define OK 1

#define Status int

#define HASHSIZE 12  //散列表长度为12
#define NULLKEY -32768
typedef struct{
	int *elem; //数据元素基址，动态分配数组
	int count;//当前元素个数
	//int sizeindex;
}HashTable;
int m = 0;

//初始化散列表
Status InitHashTable(HashTable *H){
	int i;
	m = HASHSIZE;
	H->count = m;
	H->elem = (int *)malloc(m*sizeof(int));
	for(i = 0; i < m; i ++){
		H->elem[i] = NULLKEY;
	}
	return OK;
}
//散列函数
int Hash(int key){
	return key % m;//除留余数法
}
//插入关键字进散列表
void InsertHash(HashTable *H,int key){
	int addr = Hash(key);
	while(H->elem[addr] != NULLKEY)
		addr = (addr+1) % m;
	H->elem[addr] = key;
}
//查找key是否在散列表中
Status SearchHash(HashTable H,int key,int *addr){
	*addr = Hash(key);//计算key应该在散列表中的位置
	while(H.elem[*addr] != key){
		*addr = (*addr+1) % m;
		if(H.elem[*addr] == NULLKEY || *addr == Hash(key)){//为空或者循环回到原点
			return UNSUCCESS;
		}
	}
	return SUCCESS;
}
int main(int argc, char const *argv[]){
	HashTable H,*p;
	p = &H;//将结构体变量的地址赋值给结构体指针
	InitHashTable(p);
	//将下列数插入长度为12的散列表中
	InsertHash(p,12);
	InsertHash(p,25);
	InsertHash(p,15);
	InsertHash(p,16);
	InsertHash(p,29);
	InsertHash(p,67);
	InsertHash(p,57);
	InsertHash(p,22);
	InsertHash(p,47);
	cout<<"insert done"<<endl;
	int pos = 10;
	int *addr = &pos;
	//在散列表中查找pos,是否存在
	cout<<"(0:not exist  1:exist):"<<SearchHash(H,pos,addr)<<endl;
	//addr指的是pos应该在的位置
	cout<<*addr<<endl;
	return 0;
}