#include <stdio.h>
//并查集类
class UFSet{
public:
	UFSet(int mSize);
	~UFSet(){
		delete []parent;
	}
	int Find(int i) const;//查找函数，返回元素i的根节点序号
	void Union(int x,int y);//将两个子集联合成一个集合
	//避免树退化，成为链表。将函数进行改进
	int modifiedFind(int i)const;
	void modifiedUnion(int x,int y);
	int getParent(int i);
	void divideByEqual(int x,int y);
private:
	int *parent;
	int size;	
};
UFSet::UFSet(int mSize){
	size = mSize;
	parent = new int [size];
	for(int i = 0; i < size; i ++){
		parent[i] = -1;
	}
}
int UFSet::Find(int i)const{
	for(; parent[i] >= 0; i = parent[i]);
	//如果i的双亲不为根节点，则一直向上搜索
	return i;
}
void UFSet::Union(int x,int y){
	parent[x] = y;
}
int UFSet::modifiedFind(int i)const{
	int r, t, l;
	for(r = i; parent[r] >= 0; r = parent[r]);
	//printf("%d %d\n",i,r);
	if(i!=r){
		for(t = i; parent[t] != r; t = l){
			l = parent[t];
			parent[t] = r; //将根节点到i元素路径上的节点的parent域重置，连接至根节点
			//printf("%d %d %d \n",t,l,r);
		};
	}
	return r;
}
//节点少的树并入节点多的树
void UFSet::modifiedUnion(int x,int y){
	int temp = parent[x] + parent[y];
	if(parent[x] >= parent[y]){
		parent[x] = y;
		parent[y] = temp;
	}else{
		parent[y] = x;
		parent[x] = temp;
	}
}
//返回双亲，根节点的双亲是这个树总节点数的负数
int UFSet::getParent(int i){
	return parent[i];
}
//按等价关系分组
void UFSet::divideByEqual(int x,int y){
	if(Find(x)!=Find(y)){
		Union(x,y);
	}
}
int main(int argc, char const *argv[]){
	printf("%s\n","Union-Find Set");
	UFSet uf(7);
	uf.Union(1,2);
	uf.Union(2,3);
	uf.Union(4,3);
	uf.Union(5,6);
	printf("%d\'s root is %d\n",1,uf.Find(1));//1的双亲是2，2的双亲是3，3为根节点，所以返回3
	printf("%d\'s root is %d\n",0,uf.Find(0)); //0默认是根节点，返回0

	printf("\n%s\n","modified UFSet");
	UFSet uf2(7);
	uf2.modifiedUnion(1,2);
	uf2.modifiedUnion(2,3);
	uf2.modifiedUnion(5,4);
	uf2.modifiedUnion(2,4);
	printf("%d\'s root is %d\n",3, uf2.modifiedFind(3));
	printf("%d\'s root is %d\n",5, uf2.modifiedFind(5));
	printf("%d\'s parent is %d\n",2, uf2.getParent(2));

	printf("%s\n","divide by equality");
	UFSet uf3(7);
	uf3.divideByEqual(0,1); //0和1是等价关系，被分在同一棵树中
	uf3.divideByEqual(2,3);
	uf3.divideByEqual(3,1);
	uf3.divideByEqual(4,5);
	uf3.divideByEqual(6,5);
	printf("%d\n",uf3.Find(2));
	printf("%d\n",uf3.Find(0));
	printf("%d\n",uf3.Find(3));
	printf("%d\n",uf3.getParent(1));
	printf("%d\n",uf3.getParent(0));
	printf("%d\n",uf3.getParent(3));
	printf("%d\n",uf3.Find(6));
	printf("%d\n",uf3.Find(4));
	printf("%d\n",uf3.Find(5));
	printf("%d\n",uf3.getParent(4));
	printf("%d\n",uf3.getParent(5));
	printf("%d\n",uf3.getParent(6));
	return 0;
}