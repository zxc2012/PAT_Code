#include<bits/stdc++.h>
using namespace std;
struct Node{int lchild=-1,rchild=-1,dp;}node[31];
int a[1005]={0};
vector<int> post,in;
int full=0;
int dfs(int postl,int postr,int inl,int inr,int dp){
    if(postl>postr)return -1;
    int i;
    for(i=inl;i<=inr;++i)if(in[i]==post[postr])break;
    node[postr].lchild=dfs(postl,postl-inl+i-1,inl,i-1,dp+1);
    node[postr].rchild=dfs(postl-inl+i,postr-1,i+1,inr,dp+1);
    node[postr].dp=dp;
    if((node[postr].lchild==-1)^(node[postr].lchild==-1))full=1;
    //printf("%d ",postr);
    return postr;
}
int main(){
    int n,m,i,j,x,y;
    scanf("%d",&n);
    post.resize(n);in.resize(n);
    for(i=0;i<n;++i){scanf("%d",&post[i]);a[post[i]]=i;}
    for(i=0;i<n;++i)scanf("%d",&in[i]);
    dfs(0,n-1,0,n-1,0);
    scanf("%d",&m);getchar();
    for(i=0;i<m;++i){
        string s;
        getline(cin,s);
        if(s.find("root",0)!=string::npos){
            sscanf(s.c_str(),"%d",&x);
            if(x==post[n-1])printf("Yes\n");
            else printf("No\n");
        }
        if(s.find("siblings",0)!=string::npos){
            sscanf(s.c_str(),"%d and %d",&x,&y);
            int flag=0;
            for(j=0;j<n;++j){
                if(node[j].lchild==a[x]&&node[j].rchild==a[y]||node[j].lchild==a[y]&&node[j].rchild==a[x])
                {printf("Yes\n");flag=1;break;}
            }
            if(flag==0)printf("No\n");
        }
        if(s.find("parent",0)!=string::npos){
            sscanf(s.c_str(),"%d is the parent of %d",&x,&y);
            //printf("\n%d %d",a[x],a[y]);
            if(node[a[x]].lchild==a[y]||node[a[x]].rchild==a[y])printf("Yes\n");
            else printf("No\n");
        }
        if(s.find("left",0)!=string::npos){
            sscanf(s.c_str(),"%d is the left child of %d",&x,&y);
            if(node[a[y]].lchild==a[x])printf("Yes\n");
            else printf("No\n");
        }
        if(s.find("right",0)!=string::npos){
            sscanf(s.c_str(),"%d is the right child of %d",&x,&y);
            if(node[a[y]].rchild==a[x])printf("Yes\n");
            else printf("No\n");
        }
        if(s.find("same",0)!=string::npos){
            sscanf(s.c_str(),"%d and %d",&x,&y);
            if(node[a[y]].dp==node[a[x]].dp)printf("Yes\n");
            else printf("No\n");
        }
        if(s.find("full",0)!=string::npos){
            if(full==0)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
