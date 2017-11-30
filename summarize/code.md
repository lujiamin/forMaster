## 天勤模拟卷8套
#### 一
整型一维数组，有正数有负数，求连续的一个或多个整数组成的子数组，使其和最大.  
算法思想：遍历数组，用事先定义好的求和变量，加上当前元素得到一个新的和，先判断这个和是否比前面已经记录的最大子数组和大，如果大，则更新此记录。然后判断这个和是否为负数，如果为负数，将这个和重置为0.  
```
void findmaxSum(int a[],int n){
    int sum;
    int max;
    int i;
    max = a[0];
    sum = 0;
    for(i=0;i<n;i++){
        sum += a[i];
        if(sum > max){
            max = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    printf("%d\n",max);
}
// 时间复杂度O(n),空间复杂度O(1)
```  
#### 二  
实现判断一个整数数组是否是某二叉排序树的后续遍历的结果，返回true和false，假设数字之间各不相同.  
算法思想：后续遍历的最后一个结点是根结点，将整数序列分为两部分，第一部分是左子树，第二部分是右子树，这是一个递归过程.  
```
bool verify(int seq[],int length){
    if(seq == NULL || length < 0){
        return false;
    }
    int root = seq [length-1];
    int i = 0;
    for(;i < length-1;i++){
        if(seq[i] > root){
            break;
        }
    }
    int j = i; // 第一个大于根节点
    for(;j < length-1;j++){
        if(seq[j] < root){
            return false;
        }
    }
    // 左子树
    bool left = true;
    if(i > 0){
        left = verify(seq,i);
    }
    // 右子树
    bool right = true;
    if(i < length-1){
        right = verify(seq+i,length-i-1);
    }
    return (left && right);
}
```  
#### 三  
二叉排序树，结点结构(lchild，rchild，data),给定一个递增有序的二叉排序树(前序遍历得递增)，根结点为root，求使该二叉排序树转变为递减的二叉排序树(前序遍历)，返回根节点指针  
算法思想：递归处理左右子树  
```
struct Node{
    int data;
    Node *lchild;
    Node *rchild;
}
Node *reverse(Node *p,Node *m){
    Node *l,*r,*lm,*rm;
    if(p->rchild != NULL){
        r = reverse(p->rchild,rm);
    }
    if(p->lchild != NULL){
        l = reverse(p->lchils,lm);
    }
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = p->data;
    q->lchild = q->rchild = NULL;
    m = q;
    if(r != NULL){
        if(l != NULL)
            rm->lchild = l;
        rm->rchild = q;
        return r;
    }
    if(l != NULL){
        lm->lchild = q;
        return l;
    }
    return q;
}
//时间复杂度 O(n)
```  
#### 四  
链表结点  
```
struct nextNode{
    int data;
    int fre;
    struct nextNode *next;
}
```  
所有结点按fre递减链接，fre为该结点访问次数，初始为0,编写一个查找函数，查找与给定值相等的结点，如果找到，相应的fre 加一，然后将他前移至与结点fre相等的结点的后面。  
算法思想：设置三个指针，p作为检测指针，顺序检测，pre跟在p后面，移动结点的时候用。设q指针用于记录fre改变的结点位置，插入p的时候使用.  
```
bool organize(nextNode *f,int value,nextNode *&p){
    nextNode *pre,*q;
    p = f->next;
    q = pre = f;
    while(p != NULL && P->data != value){
        if(pre != f && pre->fre > p->fre){
            q = pre;
        }
        pre = p;
        p = p->next;
    }
    if(p = NULL){
        return false;
    }
    // 移动结点
    p->fre++;
    pre->next = p->next;
    p->next = q->next;
    q->next = p;
    return true; 
}
```  
#### 五  
一个升序整数数组{1,2,4,7,11,15}以及一个整数15，可以找到4+11=15，实现查找这两个数的算法，尽可能高效.输出任意一对.  
算法思想：从前和后依次向中间移动，和相等时正好符合题意.  
```
bool find(int a[],int len,int sum){
    bool found = false;
    if(len < 1){
        return found;
    }
    int start = 0;
    int end = len-1;
    while(start < end){
        int curSum = a[start] + a[end];
        if(curSUm == sum){
            printf("%d  %d",a[start],a[end]);
            found = true;
            break;
        }else if(curSum > sum){
            end--;
        }else{
            start++;
        }
    }
    return found;
    //时间复杂度O(n)
}
```  
#### 六  
设有向无环图G以邻接矩阵方式存储，G[i][j]存放的是从结点i到结点j的边权，G[i][j]=0代表没有直接边，编写程序，求G中最长的路径长度.  
算法思想：运用弗洛伊德(floyd)算法，将全部边权取相反数后为负数.  
```
int floyd(int a[][]){
    int dist[n][n];
    //取反
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=-a[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j] > dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    //找到最小的取反即是最长路径
    int max = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(max < -dist[i][j]){
                max = -dist[i][j];
            }
        }
    }
    return max;
}
//时间复杂度O(n^3)
```  
同样的思想可用于求图的闭包(两个结点之间是否相通)
#### 七  
加入一个关键字到最大堆中，调整最大堆  
算法思想：从标号为[n/2]开始向上，对每个结点和左右子树进行调整，最开始需要判断n是左结点还是右结点，之后的结点，左右子树都有，无需判断.  
```
int k[n];  
void heap(){
    int i = n/2;
    if(n%2 == 1){
        if(k[i] < k[n-1] && k[n-1] > k[n]){
            swap(k[n-1],k[i]);
        }
        if(k[i] < k[n] && k[n-1] < k[n]){
            swap(k[n],k[i]);
        }
    } //右结点
    else{
        if(k[i] < k[n]){
            swap(k[i],k[n]);
        }
    }
    i = i/2;
    while(i>0){
        if(k[i] < k[n-1] && k[n-1] > k[n]){
            swap(k[n-1],k[i]);
        }
        if(k[i] < k[n] && k[n-1] < k[n]){
            swap(k[n],k[i]);
        }
        i = i/2;
    }
}
//时间复杂度O(log2(n))
```  
#### 八  
将一个带头结点的循环双链表 L=(a1,a2,....an),改造成 L=(a1,a3....an,...a4,a2);  
算法思想：保留奇数号结点，偶数号结点采用头插法插入到另外一个不带头结点的循环双链表s中，最后将两个链表相连.  
```
// 画图理解，指针结点很复杂
void modify(struct node *head){
    struct node *s = NULL;//偶结点链表
    struct node *l = head;
    struct node *p = l->next,*p1;
    l->next = l->pre = NULL;
    for(;p != l;p=p1){
        if(p->next != l){
            p1 = p->next;
            p->next = p1->next;
            p1->next->pre = p;
        }
        if(s == NULL){
            s = p1;
            p1->next = p1->pre = p1;
        }else{
            p1->next = s;
            p1->pre = s->pre;
            s->pre->next = p1;
            s->pre = p1;
            s = s->pre;
        }
    }
    p1 = p->next;
    l->pre->next = p;
    p->next = l;
    p->pre = l->pre;
    l->pre = p;
    // 合并两个链表
    if(s == NULL){
        return;
    }
    p = s->pre;
    p->next = l;
    l->pre->next = s;
    s->pre = l->pre;
    l->pre = p;
}
```