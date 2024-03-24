#include<bits/stdc++.h>
using namespace std;
int dp[40000];
int main(){
    int n,i,j,m,x;scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",&m);
        fill(dp,dp+40000,60000);
        for(j=0;j<m;++j){
            scanf("%d",&x);
            *lower_bound(dp,dp+m,x)=x;
        }
        printf("%d\n",lower_bound(dp,dp+m,60000)-dp);
    }
    return 0;
}
