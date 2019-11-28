#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int a[30000]={0};
int main(){
    int n,i,j,p;
    scanf("%ld",&n);
    for(i=2;i<=15000;++i){
        if(a[i]==0)v.push_back(i);
        for(j=0;j<v.size();++j){
            if(i*v[j]<15000)a[i*v[j]]=1;
            if(i%v[j]==0)break;
        }
    }
    printf("%d=",n);
    if(n==1)printf("1");
    for(i=0;i<v.size();++i){
        p=0;
        while(n>1&&(n%v[i]==0)){n/=v[i];++p;}
        if(p>0){
            printf("%d",v[i]);
            if(p>1)printf("^%d",p);
            if(n>1)printf("*");
            else if(n==1)break;
        }
    }
    return 0;
}
