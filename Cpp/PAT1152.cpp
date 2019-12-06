#include<bits/stdc++.h>
using namespace std;
bool isprime(long long a){
    if(a<2)return 0;
    for(long long i=2;i<=sqrt(a);++i)
        if(a%i==0)return 0;
    return 1;
}
int main(){
    int l,k;char s[1005];
    scanf("%d%d\n",&l,&k);
    scanf("%s",s);
    for(int i=0;i+k-1<strlen(s);++i){
        string ss;
        ss.insert(0,s+i,k);
        long long x=stoll(ss);
        if(isprime(x)==1){cout<<ss;return 0;}
    }
    printf("404");
    return 0;
}
