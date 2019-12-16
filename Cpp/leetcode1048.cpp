#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   int longestStrChain(vector<string>& words) {
       int m=words.size(),sum=1;
       sort(words.begin(),words.end(),cmp);
       dp[words[0]]=1;
       for(int i=1;i<m;++i){
           for(int j=0;j<words[i].size();++j){
                string ss=words[i].substr(0,j)+words[i].substr(j+1);
                dp[words[i]]=max(dp[ss]+1,dp[words[i]]);
                sum=max(sum,dp[words[i]]);
           }
       }
       return sum;
   }
private:
   unordered_map<string,int>dp;
   static bool cmp(string& a,string& b){return a.size()<b.size();}
};
int main(){
    int n,i;
    scanf("%d",&n);
    vector<string> v(n);
    for(i=0;i<n;++i)cin>>v[i];
    Solution s;
   	printf("%d",s.longestStrChain(v));
    return 0;    
}
