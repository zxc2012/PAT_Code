#include<bits/stdc++.h>
using namespace std;
int dp[301],a[301],father[301];
vector<vector<int>>g;
int main(){
    int n,m,i;scanf("%d",&n,&m);
    g.resize(n+1);
    for(i=1;i<=n;++i){
        scanf("%d%d",&father[i],&a[i]);
        g[father[i]].push_back(i);
    }
    for(i=1;i<=m;++i)for(j=1;j<=n;++j)
    if(father)dp[i]=max(dp[i],dp[i-1]+a[j])
    return 0;
}