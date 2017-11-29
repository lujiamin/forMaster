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