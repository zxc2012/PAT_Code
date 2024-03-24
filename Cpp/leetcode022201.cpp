#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        fill(l,l+50001,0);
        int s=0,m=0;
        int n=light.size();
        for(int i=0;i<n;++i){
            int p=light[i];m=max(m,p);
            for(int j=p;j<=n;++j){
                l[j]++;
            }
            if(l[m]==m)s++;
        }
        return s;
    }
private:
    int l[50001];
};
int main(){
    Solution s;
    vector<int> v=
    s.sortByBits()
    return 0;
}