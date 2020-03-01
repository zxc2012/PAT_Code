#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int n=digits.size();string s;int flag=0,pos=0;
        vector<char> d2s(n);
        sort(digits.begin(),digits.end(),greater<int>());
        if(digits[0]==0)return "0";
        for(int i=0;i<n;++i){
            sum[i+1]=sum[i]+digits[i];d2s[i]=digits[i]+'1'-1;
            if(pos&&digits[i]==0)pos=i;
        }
        for(int i=n-1;i>=0;--i){
            s="";
            for(int j=0;j+i<n;++j){
                if((sum[j+i+1]-sum[j])%3==0){
                    printf("%d %dto%d\n",sum[j+i+1]-sum[j],j,j+i);s.insert(s.begin(),d2s.begin()+j,d2s.begin()+j+i+1);
                    s.insert(s.end(),d2s.begin()+pos,d2s.end());
                    flag=1;break;
                }
            }
            if(flag==1)break;
        }
        return s;
    }
private:
    int sum[10005]={0};
};
int main(){
    Solution s;
    vector<int> v=
    s.sortByBits()
    return 0;
}