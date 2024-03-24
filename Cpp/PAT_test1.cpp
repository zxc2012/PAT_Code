#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return a!=0?(b,a%b):0;}
struct Node{int n,a;};
vector<int> v;
int main(){
    int n,i,j,r,k,m;
    for(i=1;i<=n;++i){
        scanf("%d%d",&k,&m);
        printf("Case %d\n",i);
        for(j=1;9*(j+1)<m&&(j+1<=k);++j){
            int flag=0;
            int x=gcd(m,8+9*j);
            if(x==1)flag=1;
            for(r=2;r<=sqrt(x);++r){
                if(x%r==0){flag=1;break;}
            }
            if(flag==1)continue;
            printf("%d",m-9*j);
            if(k-j-1==1){
                printf("%d");
                for(r=0;r<j+1;++r)printf("9");
                v.push_back(1);
            }
            else
            for(r=8;r>=0;--r){
                int y=m-9*j-1-r;
                printf("%d%d",y,r);
                for(r=0;r<j+1;++r)printf("9");
                v.push_back(1);
            }
        }
        if(v.size()==0)printf("No Solution\n");
    }
    return 0;
}
