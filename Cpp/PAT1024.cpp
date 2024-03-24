#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,r,tp;int k,i,j,temp,carry=0;
    cin>>s>>k;
    r=s;
    reverse(r.begin(),r.end());
    for(i=0;i<k;++i){
        if(r==s){
            cout<<r<<endl;
            printf("%d",i);
            break;
        }
        else{
            tp.clear();carry=0;
            for(j=r.size()-1;j>=0;--j){
                temp=r[j]-'0'+s[j]-'0'+carry;
                carry=temp/10;
                tp+=to_string(temp%10);
                if(j==0&&carry!=0)tp+=to_string(carry);
            }
            reverse(tp.begin(),tp.end());
            r=s=tp;
            reverse(r.begin(),r.end());
        }
        if(i==k-1){
            cout<<s<<endl;
            printf("%d",k);break;
        } 
    }
    return 0;
}
