#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSteps(string s, string t) {
        int sum;
        fill(a,a+26,0);fill(b,b+26,0);
        for(auto &p:s)a[(int)(p-'a')]++;
        for(auto &p:t)b[(int)(p-'a')]++;
        for(int i=0;i<26;++i){
            sum+=(a[i]>b[i]?a[i]-b[i]:0);
        }
        return sum;
    }
private:
    int a[26]={0},b[26]={0};
};
int main(){
    Solution s;
    return 0;
}