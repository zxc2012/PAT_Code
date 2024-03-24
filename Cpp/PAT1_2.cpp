#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
vector<string> v,temp;
bool cmp(string a,string b){return a.substr(6,8)<b.substr(6,8);}
int main(){
    int n,m,i;scanf("%d",&n);
    for(i=0;i<n;++i){
        string x;if(i==0)getchar();
        getline(cin,x);
        mp[x]=1;
    }
    scanf("%d",&m);
    for(i=0;i<m;++i){
        string x;if(i==0)getchar();
        getline(cin,x);
        temp.push_back(x);
        if(mp[x]!=0)v.push_back(x);
    }
    printf("%d\n",v.size());
    if(v.size()==0)cout<<*min_element(temp.begin(),temp.end(),cmp);
    else cout<<*min_element(v.begin(),v.end(),cmp);
    return 0;
}
