#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   int longestStrChain(vector<string>& words) {
       int m=words.size();
       dp.resize(m,1);
       sort(words.begin(),words.end(),cmp);
       for(int i=m-2;i>=0;--i)
       for(int j=i+1;j<m;++j){
           int p=0,x1=words[i].size(),x2=words[j].size();
           string ss=words[i],xx="";
           if(x2==x1)continue;
           if(x2>x1+1)break;
           printf("\n%d (%d)%s (%d)%s",p,i,ss.c_str(),j,words[j].c_str());
           while(words[j][x2-p]==words[i][x1-p]){
                ++p;if(p>x1)break;
            }
           if(p>x1){dp[i]=max(dp[j]+1,dp[i]);continue;}
           xx+=words[j][x2-p];
           ss.insert(x1-p+1,xx);
           if(ss==words[j])dp[i]=max(dp[j]+1,dp[i]);
       }
       return *max_element(dp.begin(),dp.end());
   }
private:
   vector<int>dp;
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
