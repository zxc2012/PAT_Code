## 1123 Is It a Complete AVL Tree (30分)
[题目链接](https://pintia.cn/problem-sets/994805342720868352/problems/994805351302414336)
存一个模板，以后背这个
```cpp
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
struct sq{int i,data;};
vector<sq> v;
bool cmp(sq& a,sq& b){return a.i<b.i;}
node* l(node* tree){
    node* temp=tree->right;
    tree->right=temp->left;
    temp->left=tree;
    return temp;
}
node* r(node* tree){
    node* temp=tree->left;
    tree->left=temp->right;
    temp->right=tree;
    return temp;
}
node* lr(node* tree){
    tree->left=l(tree->left);
    return r(tree);
}
node* rl(node* tree){
    tree->right=r(tree->right);
    return l(tree);
}
int height(node* tree){
    if(tree==NULL)return 0;
    int l=height(tree->left);
    int r=height(tree->right);
    return max(l,r)+1;
}
node* insert(node* tree,int v){
    if(tree==NULL){
        tree=new node();
        tree->data=v;
    }
    else if(v<tree->data){
        tree->left=insert(tree->left,v);
        if(height(tree->left)-height(tree->right)>=2){
            if(v<tree->left->data)tree=r(tree);
            else tree=lr(tree);
        }
    }
    else{
        tree->right=insert(tree->right,v);
        if(height(tree->right)-height(tree->left)>=2){
            if(v>tree->right->data)tree=l(tree);
            else tree=rl(tree);
        }
    }
    return tree;
}
void dfs(node* tree,int i){
    if(tree==NULL)return ;
    v.push_back({i,tree->data});
    dfs(tree->left,2*i);
    dfs(tree->right,2*i+1);
}
int main(){
    int n,i,m,judge=1;
    scanf("%d",&n);node* tree=NULL;
    for(i=0;i<n;++i){
        scanf("%d",&m);
        tree=insert(tree,m);
    }
    dfs(tree,1);
    sort(v.begin(),v.end(),cmp);
    for(i=0;i<v.size();++i){
        printf("%d",v[i].data);
        judge=i!=0&&v[i].i!=v[i-1].i+1?0:judge;
        if(i!=v.size()-1)printf(" ");
    }
    if(judge==1)printf("\nYES");
    else printf("\nNO");
    return 0;
}
```