# 剑指offer
### 01二维数组的查找
```cpp
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int n=array.size(),m=array[0].size();
        int a=0,b=m-1;
        while(a<n&&b>=0){
            if(array[a][b]==target)return 1;
            if(array[a][b]<target)a++;
            else --b;
        }
        return 0;
    }
};
```
### 02替换空格
>开辟新存储空间
```cpp
class Solution {
public:
    void replaceSpace(char *str,int length) {
        string s="";
        for(int x=0;x<length;++x){
            if(str[x]!=' ')s+=str[x];
            else s+="%20";
        }
        strcpy(str,s.c_str());
    }
};
```
>原字符串修改
```cpp
class Solution {
public:
	void replaceSpace(char *str,int length) {
            int len=0,j;
            for(int i=0;i<length;++i)if(str[i]==' ')++len;
            j=length+2*len-1;
            for(int i=length-1;i>=0;--i){
                if(str[i]==' '){
                    str[j--]='0';str[j--]='2';str[j--]='%';
                }else str[j--]=str[i];
            }
	}
};
```
### 03从尾到头反转链表
>不能改变链表结构
```cpp
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int>s;
        vector<int>v;
        for(auto p=head;p!=NULL;p=p->next)s.push(p->val);
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};
```
>可以改变
```cpp
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>v;
        for(auto p=head;p!=NULL;p=p->next)v.push_back(p->val);
        reverse(v.begin(),v.end());
        return v;
    }
};
```
### 04重建二叉树
```cpp
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        p=pre,in=vin;
        int n=pre.size();
        TreeNode* t=build(0,n-1,0,n-1);
        return t;
    }
private:
    vector<int>p,in;
    TreeNode* build(int prel,int prer,int inl,int inr){
        if(prel>prer)return NULL;
        TreeNode* t=new TreeNode(p[prel]);int i;
        for(i=inl;i<=inr;++i)if(in[i]==p[prel])break;
        t->left=build(prel+1,prel+i-inl,inl,i-1);
        t->right=build(prel+i-inl+1,prer,i+1,inr);
        return t;
    }
};
```
### 12 Pow(x,n)
快速幂+迭代
```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        if(n<0)return 1.0/process(x,-(long long)n);
        else return process(x,n);
    }
private:
    double process(double x,long long n){
        if(x==0||x==1)return x;
        double s=1.0,base=x;
        while(n!=0){
            if(n&1)s*=base;
            base*=base;
            n>>=1;
        }
        return s;
    }
};
```
### 15 反转链表
策略:在使用递推前保存pnext
```cpp
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pnext=NULL;
        ListNode* b=NULL;
        for(auto p=pHead;p!=NULL;p=pnext){
            pnext=p->next;
            p->next=b;
            b=p;
        }
        return b;
    }
};
```
### 22 栈的压入、弹出序列
```cpp
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int n=pushV.size();
        int i=0;
        for(int p=0;p<n;++p){
            while(present.empty()||present.top()!=popV[p]){
                if(i==n)break;
                present.push(pushV[i++]);
            }
            if(present.top()==popV[p])
                present.pop();
            else return false;
        }
        return true;
    }
private:
    stack<int> present;
};
```
## 23 二叉搜索树的后序遍历序列
```cpp
bool VerifySquenceOfBST(vector<int> sequence) {
    stack<int> s;
    int root=INT_MAX;
    reverse(sequence.begin(),sequence.end());
    if(sequence.size()==0)return false;
    for(int &p:sequence){
        if(p>root)return false;
        while(!s.empty()&&s.top()>p){
            root=s.top();
            s.pop();
        }
        s.push(p);
    }
    return true;
}
```
### 31 栈的压入、弹出序列
```cpp
bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    stack<int> s;
    int n = popV.size();
    int j =0;
    for(int i =0;i<n;++i){
        while(s.empty()||popV[i]!=s.top()&&j<n)s.push(pushV[j++]);
        if(popV[i]==s.top())s.pop();
    }
    return s.empty();
}
```
### 37 两个链表的第一个公共节点
>法1:找到差值后找公共
```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int la=0,lb=0;
    for(ListNode* p=headA;p;p=p->next)la++;
    for(ListNode* p=headB;p;p=p->next)lb++;
    ListNode *p=headA,*q=headB;
    int len=lb-la;
    if(la>lb){
        len=-len;
        p=headB,q=headA;
    }
    for(int i=0;i<len;++i)q=q->next;
    while(p&&p!=q){
        p=p->next;
        q=q->next;
    }
    return p;
}
```
>法2:双指针,利用两个链表合并后长度-公共长度时一定相遇
```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p=headA,*q=headB;
    while(p!=q){
        p=p==NULL?headB:p->next;
        q=q==NULL?headA:q->next;
    }
    return p;
}
```
