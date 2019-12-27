#include<bits/stdc++.h>
using namespace std;
struct Node{
    int v,k,c,l;
}node[1000];
int dp[1000];
inline bool cmp(Node a,Node b){return a.v<b.v;}
int main(){
    int n,i,j,x,total=0;scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d%d%d%d",&node[i].v,&node[i].k,&node[i].c,&node[i].l);
        total+=node[i].k+node[i].c*node[i].l;
    }
    scanf("%d",&i);
    sort(node,node+n,cmp);
    for(i=0;i<n-1;++i){
        int index=0;
        for(j=i+1;j<n;++j){
            x=i-1<0?total:dp[i-1];
            int y=x-node[i].k+(node[j].c-node[i].c)*node[i].l;
            if(y<x){
                dp[i]=y;index=j;
            }else dp[i]=x;
        }
        if(index>0)node[index].l+=node[i].l;
    }
    x=n-2<0?total:dp[n-2];
    printf("%d",x);
    return 0;
}
