#include<bits/stdc++.h>
using namespace std;
const int inf=500000;
struct edge{
    int to,next=-1,cap;
}e[4000];
int head[4000],visit[201],pre[4000],d[4000],num=-1,s,t,maxflow;
inline void add(int u,int v,int c){
    e[++num]={v,head[u],c};head[u]=num;
    e[++num]={u,head[v],0};head[v]=num;
}
bool bfs(){
    queue<int>q;
    q.push(s);
    for(int i=0;i<num;++i)visit[i]=0;
    visit[s]=1;d[s]=inf;
    while(!q.empty()){
        int x=q.front();q.pop();//printf("%d ",x);
        for(int i=head[x],v;i!=-1;i=e[i].next){
            if(!visit[v=e[i].to]&&e[i].cap){
                q.push(v);visit[v]=1;
                d[v]=min(d[x],e[i].cap);
                pre[v]=i;
            }
        }
    }
    return visit[t];
}
int update(){
    while(bfs()){//printf("\n");
        int i=t;
        while(i!=s){
            i=pre[i];
            e[i].cap-=d[t];e[i^1].cap+=d[t];
            i=e[i^1].to;
        }
        maxflow+=d[t];
    }
    return maxflow;
}
int main(){
    int n,m,x,a,b,c;
    scanf("%d%d%d",&n,&m,&x);
    fill(head,head+400,-1);
    s=1,t=n;
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    if(update()){    
        if(x%maxflow==0)printf("%d %d",maxflow,x/maxflow);
        else printf("%d %d",maxflow,x/maxflow+1);
    }
    else printf("Orz Ni Jinan Saint Cow!");
    return 0;
}
