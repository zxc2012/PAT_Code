#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,v,p;
    scanf("%d%d",&n,&m);
    vector<int>dp(n+1);
    for(int i=0;i<m;++i){
        scanf("%d%d",&v,&p);
        for(int j=n;j>=0;--j)
        if(j>=v)dp[j]=max(dp[j],dp[j-v]+v*p);
    }
    printf("%d",dp[n]);
    return 0;
}
