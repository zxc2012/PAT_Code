#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,temp=0,m,sum=0;
    cin>>n;
    for(i=0;i<n;++i){
        cin>>m;
        if(m>temp)sum+=6*(m-temp);
        else sum+=4*(temp-m);
        temp=m;
    }
    sum+=n*5;
    printf("%d",sum);
    return 0;
}