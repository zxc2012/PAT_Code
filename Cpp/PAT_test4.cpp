#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
vector<vector<int>>g;
vector<int> visit,d;
int main(){
    int v,e,k,i,j,r,c1,c2,w,start,x;
    scanf("%d%d",&v,&e);
    g.resize(v+1);visit.resize(v+1,0);d.resize(v+1,0);
    for(i=0;i<=v;++i)g[i].resize(v+1,inf);
    for(i=0;i<e;++i){
        scanf("%d%d%d",&c1,&c2,&w);
        g[c1][c2]=w;
        g[c2][c1]=w;
    }
    scanf("%d",&k);
    for(i=0;i<k;++i){
        fill(visit.begin(),visit.end(),0);
        fill(d.begin(),d.end(),inf);
        scanf("%d",&start);
        int u=0;
        d[start]=0;visit[start]=1;
        for(j=1;j<=v;++j){
            if(!visit[j]&&g[start][j]<d[j])d[j]=g[start][j];
        }
        for(j=1;j<v;++j){
            scanf("%d",&x);
            for(r=1;r<=v;++r){
                if(!visit[r]&&d[r]<d[x]){u=1;break;}
            }
            if(u==1)continue;
            visit[x]=1;
            for(r=1;r<=v;++r){
                if(!visit[r]&&d[x]+g[x][r]<d[r])d[r]=d[x]+g[x][r];
            }
        }
        if(u==1)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
