#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;int i,carry=0,temp;
    cin>>s;
    vector<int> v1,v2,v3;
    for(i=s.size()-1;i>=0;--i){
        int m=s[i]-'0';
        v1.push_back(m);
        temp=m*2+carry;
        carry=temp/10;
        v2.push_back(temp%10);
        if(carry!=0&&i==0)v2.push_back(carry);
    }v3=v2;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(v1==v2)printf("Yes\n");
    else printf("No\n");
    for(i=v3.size()-1;i>=0;--i)printf("%d",v3[i]);
    return 0;
}
