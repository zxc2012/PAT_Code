#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=1,T,m1,m2,i,j,fr_sum=0,bk_sum=0,sq=1;
    while(~scanf("%d",&n),n){
        scanf("%d",&T);
        vector<int> t(n-1);
        vector<vector<int>>fr_train(T+1,vector<int>(n));
        vector<vector<int>>bk_train(T+1,vector<int>(n));
        vector<vector<int>>dp(T+1,vector<int>(n));
        for(auto &p:t)scanf("%d",&p);
        scanf("%d",&m1);vector<int> fr(m1);
        for(auto &p:fr){scanf("%d",&p);fr_sum+=p;}
        scanf("%d",&m1);vector<int> bk(m1);
        for(auto &p:bk){scanf("%d",&p);bk_sum+=p;}
        /****init******/
        for(auto &p:fr){
            int x=0;
            for(i=0;(x=p+i*fr_sum+i*bk_sum)<=T;++i){
                fr_train[x][0]=1;
                for(j=0;j<n-1;++j){
                    if((x+=t[j])<=T)fr_train[x][j+1]=1;
                    else break;
                }
            }
        }
        for(auto &p:bk){
            int x=0;
            for(i=0;(x=p+i*fr_sum+i*bk_sum)<=T;++i){
                bk_train[x][n-1]=1;
                for(j=n-1;j>0;--j){
                    if((x+=t[j-1])<=T)bk_train[x][j-1]=1;
                    else break;
                }
            }
        }
        /***begin***/
        dp[T][n-1]=0;
        for(i=n-2;i>=0;--i)dp[T][i]=T+1;
        for(i=T-1;i>=0;--i)
        for(j=n-1;j>=0;--j){
            dp[i][j]=dp[i+1][j]+1;
            if(fr_train[i][j]==1&&i+t[j]<=T&&j+1<n){dp[i][j]=min(dp[i+t[j]][j+1],dp[i][j]);//printf("\nT%d:%d->%d",i,j,j+1);
            }
            if(bk_train[i][j]==1&&i+t[j-1]<=T&&j-1>=0){dp[i][j]=min(dp[i+t[j-1]][j-1],dp[i][j]);//printf("\nT%d:%d->%d",i,j,j-1);
            }
        }
        printf("Case Number %d: ",sq);
        if(dp[0][0]>T)printf("impossible\n");
        else printf("%d\n",dp[0][0]);
        sq++;
    }
    return 0;
}
