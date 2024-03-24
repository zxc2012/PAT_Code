#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t,i,j,r,ans;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d%d",&m,&t);
        vector<int>dp(t+1,-1);dp[0]=0;
        for(j=1;j<=m;++j){
            scanf("%d",&r);
            for(int k=t-1;k>=r;--k)dp[k]=max(dp[k],dp[k-r]+1);
        }
        for(ans=j=t-1;j>=0;--j)if(dp[ans]<dp[j])ans=j;
        printf("Case %d: %d %d\n",i+1,dp[ans]+1,ans+678);
    }
    return 0;
}