#include<bits/stdc++.h>
using namespace std;
float d(int xi,int yi,int xj,int yj){
    return sqrt((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj));
}
int main(){
    int n,i,j;
    while(~scanf("%d",&n)){
        vector<int> x(n),y(n);
        vector<vector<float>> dp(n,vector<float>(n,0.0));
        for(i=0;i<n;++i)scanf("%d%d",&x[i],&y[i]);
        dp[1][0]=d(x[1],y[1],x[0],y[0]);
        for(i=2;i<n;++i){
            for(j=0;j<i-1;++j)dp[i][j]=dp[i-1][j]+d(x[i-1],y[i-1],x[i],y[i]);
            for(int k=0;k<i-1;++k)
            dp[i][j]=dp[i-1][k]+d(x[k],y[k],x[i],y[i]);
        }
        printf("%.2f\n",dp[n][n-1]+d(i-1,i));
    }
    return 0;
}
