#include<bits/stdc++.h>
using namespace std;
vector<int> v,temp;
int main(){
    int maxi=0,s;
    unsigned int n,m,i,j;//2^31和2^30细抠
    scanf("%d",&n);m=n;
    for(i=2;i*i<=n;++i){//质数、平方数、连乘数
        s=0;n=m;j=i;
        temp.clear();
        while(n>1&&n%j==0){
            n/=j;
            temp.push_back(j);
            ++j;++s;
        }//2*3*4-->从3开始3*?(2的影响)
        if(s>maxi){v=temp;maxi=s;}
    }
    if(v.size()==0){printf("1\n%d",n);return 0;}
    printf("%d\n",v.size());
    for(i=0;i<v.size();++i){
        printf("%d",v[i]);
        if(i!=v.size()-1)printf("*");
    }
    return 0;
}
