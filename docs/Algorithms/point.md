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