#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m=group.size();
        for(int i=0;i<101;++i)for(int j=0;j<101;++j)for(int k=0;k<101;++k)
        dp[i][j][k]=0;
        for(int i=0;i<=profit[0];++i)for(int j=group[0];j<=n;++j)
        dp[i][j][0]=1;
        for(int i=0;i<=n;++i)dp[0][i][0]++;
        for(int k=1;k<m;++k)for(int j=0;j<=n;++j)for(int i=0;i<=minProfit;++i){
            int x;
            if(j-group[k]<=group[0])x=0;
            else if(i-profit[k]<=0)x=dp[0][j-group[k]][k-1];
            dp[i][j][k]=dp[i][j][k-1]%1000000007+x%1000000007;
            printf("%d =%d+ %d\n",dp[i][j][k],dp[i][j][k-1],x);
        }
        return dp[minProfit][n][m-1]%1000000007;

    }
private:
    long long dp[101][101][101];
};
int main(){
    Solution s;
    vector<int>group={2,3,5};
    vector<int> profit = {6,7,8};
    int n=10;
    int minProfit=5;
    s.profitableSchemes(n,minProfit,group,profit);
}