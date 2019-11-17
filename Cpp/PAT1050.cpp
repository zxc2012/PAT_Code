#include<bits/stdc++.h>
using namespace std;
int a[256]={0};
int main(){
    string s,ss;
    getline(cin,s);
    getline(cin,ss);
    int i;
    for(i=0;i<ss.size();++i)
    a[ss[i]]=1;
    for(i=0;i<s.size();++i){
        if(a[s[i]]==1){
        s.erase(i,1);i--;
        }
    }
    cout<<s;
    return 0;
}
