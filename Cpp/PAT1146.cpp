#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<int> v,temp;
int main(){
    int n,m,k,i,j,r,c1,c2;
    scanf("%d%d",&n,&m);
    g.resize(n+1);temp.resize(n);
    for(i=0;i<=n;++i)g[i].resize(n+1,0);
    for(i=0;i<m;++i){
        scanf("%d%d",&c1,&c2);
        g[c1][c2]=1;
    }
    scanf("%d",&k);
    for(i=0;i<k;++i){
        int flag=0;
        for(j=0;j<n;++j){
            scanf("%d",&temp[j]);
            if(flag==0)for(r=0;r<j;++r)
                if(g[temp[j]][temp[r]]==1){flag=1;break;}
        }
        if(flag==1)v.push_back(i);
    }
    for(i=0;i<v.size();++i){
        printf("%d",v[i]);
        if(i!=v.size()-1)printf(" ");
    }
    return 0;
}
