#include<bits/stdc++.h>
using namespace std;
vector<int>father,dp,pre,in;
void dfs(int prel,int prer,int inl,int inr,int d){
    if(prel>=prer)return;
    int i;//printf("\n%d-->%d,%d",prel,prer,pre[prel]);
    for(i=prel+1;i<=prer;++i){/*printf("%d",pre[i]);*/father[i]=prel;dp[i]=d+1;}
    for(i=inl;i<=inr;++i){if(in[i]==pre[prel])break;}
    dfs(prel+1,i-inl+prel,inl,i-1,d+1);
    dfs(i-inl+prel+1,prer,i+1,inr,d+1);
}
int main(){
    int m,n,i,c1,c2;
    scanf("%d%d",&m,&n);
    father.resize(n+1);pre.resize(n+1);in.resize(n+1);dp.resize(n+1);
    for(i=1;i<=n;++i)scanf("%d",&in[i]);
    for(i=1;i<=n;++i)scanf("%d",&pre[i]);
    father[1]=1;dp[1]=0;
    dfs(1,n,1,n,0);
    for(i=0;i<m;++i){
        int t,son,mother,t1,t2;
        scanf("%d%d",&c1,&c2);
        auto x=find(pre.begin()+1,pre.end(),c1);
        auto y=find(pre.begin()+1,pre.end(),c2);
        if(x==pre.end()&&y==pre.end())printf("ERROR: %d and %d are not found.\n",c1,c2);
        else if(x==pre.end()&&y!=pre.end())printf("ERROR: %d is not found.\n",c1);
        else if(x!=pre.end()&&y==pre.end())printf("ERROR: %d is not found.\n",c2);
        else{
            t1=(int)(x-pre.begin());t2=(int)(y-pre.begin());
            t=son=dp[t1]<=dp[t2]?t2:t1;mother=dp[t1]<=dp[t2]?t1:t2;
            while(dp[son]>dp[mother])son=father[son];
            if(son==mother)printf("%d is an ancestor of %d.\n",pre[mother],pre[t]);
            else{
                while(son!=mother){son=father[son];mother=father[mother];}
                printf("LCA of %d and %d is %d.\n",c1,c2,pre[mother]);
            }
        }
    }
    return 0;
}
