#include<bits/stdc++.h>
using namespace std;
int a[12000]={0};
vector<int> p,v;
int main(){
    int i,j,c1,c2,m,s;
    for(i=2;i<=12000;++i){
        if(a[i]==0){a[i]=1;p.push_back(i);}
        for(j=0;j<p.size();++j){
            if(p[j]*i<=12000)a[p[j]*i]=1;
            if(i%p[j]==0)break;
        }
    }
    cin>>c1>>c2;
    auto x=upper_bound(p.begin(),p.end(),c1);
    if(c1!=*(x-1)||x==p.begin())c1=*x;//printf("\n%d",c1);
    v.resize(c1,0);
    for(i=0;i<c2;++i){
        scanf("%d",&m);
        for(j=0;j<c1;++j){
            s=(m+j*j)%c1;
            if(v[s]==0){
                v[s]=1;    
                printf("%d",s);
                break;
            }
        }
        if(j==c1)printf("-");
        if(i!=c2-1)printf(" ");
    }
    return 0;
}
