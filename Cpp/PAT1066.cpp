#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
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
int main(){
    int n,i,m;
    scanf("%d",&n);node* tree=NULL;
    for(i=0;i<n;++i){
        scanf("%d",&m);
        tree=insert(tree,m);
    }
    printf("%d",tree->data);
    return 0;
}