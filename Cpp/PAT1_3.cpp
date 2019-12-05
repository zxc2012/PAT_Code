#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g,visit,gang;
vector<int> father,sus;
unordered_map<int,int>mp;
int findf(int v){
    if(v==father[v])return v;
    else{
        int x=findf(father[v]);
        father[v]=x;
        return x;
    }
}
void uni(int a,int b){
    int fa=findf(a);
    int fb=findf(b);
    if(fa!=fb)father[fa]=fb;
}
int main(){
    int k,n,m,i,j,c1,c2,w,total;
    scanf("%d%d%d",&k,&n,&m);
    g.resize(n+1);visit.resize(n+1);father.resize(n+1);gang.resize(n+1);sus.resize(n+1,0);
    for(i=0;i<=n;++i){g[i].resize(n+1,0);visit[i].resize(n+1,0);}
    for(i=0;i<m;++i){
        scanf("%d%d%d",&c1,&c2,&w);
        g[c1][c2]+=w;
    }
    iota(father.begin(),father.end(),0);
    total=0;
    for(i=1;i<=n;++i){
        int call=0,hui=0;
        for(j=1;j<=n;++j){
            if(visit[i][j]==1||j==i)continue;
            if(g[i][j]<=5&&g[i][j]>0){call++;visit[i][j]=1;}
            if(g[j][i]>0){hui++;visit[j][i]=1;}
            if(g[i][j]>0&&g[j][i]>0)uni(i,j);
        }
        if(call>k&&hui<=call/5){sus[i]=1;total++;}
    }
    if(total==0){printf("None");return 0;}
    w=1;
    for(i=1;i<=n;++i){
        if(mp[findf(i)]==0){
            mp[findf(i)]=w;
            if(sus[i]==1)gang[w].push_back(i);
            w++;
        }
        else if(sus[i]==1)gang[mp[findf(i)]].push_back(i);
    }
    for(i=1;i<=n;++i){
        for(j=0;j<gang[i].size();++j){
            printf("%d",gang[i][j]);
            if(j!=gang[i].size()-1)printf(" ");
        }
        if(gang[i].size()!=0)printf("\n");
    }
    return 0;
}
