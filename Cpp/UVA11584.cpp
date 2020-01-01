#include<bits/stdc++.h>
using namespace std;
char s[1005];int dp[1005];
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;++i){
        fill(dp,dp+1005,0);
        scanf("%s",s);dp[0]=1;int x=strlen(s);
        vector<int>m(x+1),n(x+1);
        n[0]=m[0]=n[1]=m[1]=1;
        for(int j=1;j<x;++j){
            dp[j]=dp[j-1]+1;
            for(int r=j-1;r>=0;--r)
            if(s[r]==s[j]&&m[r+1]){
                n[r]=1;
                dp[j]=min(dp[j],(r-1<0?0:dp[r-1])+1);
            }else n[r]=0;
            n[j]=n[j+1]=1;m=n;
        }
        printf("%d\n",dp[x-1]);
    }
    return 0;
}
