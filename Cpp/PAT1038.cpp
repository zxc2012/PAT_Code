#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){return a+b<b+a;};
int main(){
    int n,i;
    cin>>n;
    int flag=0;
    vector<string> v(n);
    for(i=0;i<n;++i){cin>>v[i];if(stoi(v[i])!=0)flag=1;}
    sort(v.begin(),v.end(),cmp);
    printf("%d",stoi(v[0]));
    if(flag==1)
    for(i=1;i<n;++i)cout<<v[i];
    return 0;
}