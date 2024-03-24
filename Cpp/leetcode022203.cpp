#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countOrders(int n) {
        long long x=1;
        for(int i=2;i<=n;++i){
            int y=2*i;
            x=x*y*(y-1)/2+x*y;
        }
        return x%1000000007;
    }
};
int main(){
    Solution s;
    return 0;
}