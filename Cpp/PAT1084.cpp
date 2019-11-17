#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,ss;
    map<char,int> m;
    int i,j;
    cin>>s;
    cin>>ss;
    for(i=0,j=0;j<s.size();++j)
    {
        while(s[j]!=ss[i]){
            char x=toupper(s[j]);
            if(m[x]==0){
                m[x]=1;
                printf("%c",x);
            }
            ++j;
        }
        if(s[j]==ss[i]&&i<s.size())++i;
    }
    return 0;
}
