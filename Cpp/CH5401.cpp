#include<bits/stdc++.h>
using namespace std;
int dp[6001][2],a[6001],father[6001];
vector<vector<int>>g;
void dfs(int i){
    dp[i][1]=a[i];
    for(int j=0;j<g[i].size();++j){
        int k=g[i][j];dfs(k);
        dp[i][0]+=max(dp[k][0],dp[k][1]);
        dp[i][1]+=dp[k][0];
    }
}
int main(){
    int n,i,x,y;scanf("%d",&n);
    g.resize(n+1);
    for(i=1;i<=n;++i)scanf("%d",&a[i]);
    for(i=0;i<n-1;++i){
        scanf("%d%d",&x,&y);
        g[y].push_back(x);father[x]=y;
    }
    for(i=1;i<=n;++i)if(father[i]==0){x=i;break;}
    dfs(x);
    printf("%d",max(dp[x][0],dp[x][1]));
    return 0;
}
