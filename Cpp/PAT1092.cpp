#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,ss;
    int sum=0,i;
    cin>>s>>ss;
    vector<int> v;
    v.resize(s.size(),0);
    int r=s.size();
    for(i=0;i<ss.size();++i){
        int x=s.find(ss[i]);
        if(x!=s.npos&&v[x]==0){
            v[x]=1;
            s[x]='_';
            sum++;
        }
    }
    if(sum<ss.size())printf("No %d",ss.size()-sum);
    else printf("Yes %d",r-sum);
    return 0;
}
