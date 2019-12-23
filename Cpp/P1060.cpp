#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,m,i,j;
    scanf("%d%d",&t,&m);
    vector<int>dp(t+1,0);
    vector<int>g(m),w(m);
    for(i=0;i<m;++i)scanf("%d%d",&g[i],&w[i]);
    for(i=0;i<m;++i)for(j=t-v[i].g;j>=0;--j)
    dp[j]=max(dp[j],dp[j+g[i]]+w[i]);
    printf("%d",dp[0]);
    return 0;
}
