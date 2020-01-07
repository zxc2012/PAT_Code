#include<bits/stdc++.h>
using namespace std;
int s[101],a[100],xp[100][100],dp[100][100];
int main(){
    int n,i,j,maxi=0,mini=200000;scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",&a[i]);
        s[i+1]=s[i]+a[i];s[i+1+n]=s[i+1];
    }
    for(i=0;i<n;++i)s[i+1+n]+=s[n];
    for(int z=1;z<n;++z)for(i=0;i<n;++i){        
        j=i+z;xp[i][j%n]=200000;
        for(int k=i;k<j;++k){
            xp[i][j%n]=min(xp[i][j%n],xp[i][k%n]+xp[(k+1)%n][j%n]+s[j+1]-s[i]);
            dp[i][j%n]=max(dp[i][j%n],dp[i][k%n]+dp[(k+1)%n][j%n]+s[j+1]-s[i]);
            if(z==n-1)mini=min(mini,xp[i][j%n]);
            if(z==n-1)maxi=max(maxi,dp[i][j%n]);
        }
    }
    printf("%d\n%d",mini,maxi);
    return 0;
}
