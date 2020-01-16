#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int t;fill(dp[1]+1,dp[1]+f+1,1);
        for(int i=2;i<=d;++i)for(int j=target;j>=0;--j)
            for(t=1;t<=min(j,f);++t)
            dp[i][j]=(dp[i][j]+dp[i-1][j-t])%1000000007;
        return dp[d][target];
    }
private:
     long long dp[31][1001];
};
int main(){
    Solution s;
    printf("%lld",s.numRollsToTarget(30,30,500));
    return 0;
}
