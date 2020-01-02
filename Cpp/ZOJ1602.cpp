#include<bits/stdc++.h>
using namespace std;
int dp[98][98],a[100];
int main(){
    int n,i,j;
    while(~scanf("%d",&n)){
        for(i=0;i<n;++i)scanf("%d",&a[i]);
        for(int z=0;z<n-2;++z)for(i=1;(j=i+z)<n-1;++i){
            dp[i][j]=50000000;
            for(int k=i;k<=j;++k)
            dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[k]*a[i-1]*a[j+1]);
        }
        printf("%d\n",dp[1][n-2]);
    }
    return 0;
}
