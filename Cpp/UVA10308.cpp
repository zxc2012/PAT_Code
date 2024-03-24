#include<bits/stdc++.h>
using namespace std;
int dp1[10001],dp2[10001],head[10001];
int cnt=0,maxi=0;
struct edge{int v,w,next;}Edge[20001];
inline void add_edge(int u,int v,int w){
    Edge[++cnt]={v,w,head[u]};head[u]=cnt;
}
void dfs(int s,int pre){
    for(int i=head[s];i;i=Edge[i].next){
        int v=Edge[i].v;
        if(v==pre)continue;dfs(v,s);
        if(dp1[v]+Edge[i].w>dp1[s])dp2[s]=dp1[s],dp1[s]=dp1[v]+Edge[i].w;
        else if(dp1[v]+Edge[i].w>dp2[s])dp2[s]=dp1[v]+Edge[i].w;
    }maxi=max(maxi,dp1[s]+dp2[s]);
}
int main(){
    int a,b,c,flag;char m[20];
    while(1){
        memset(head,-1,sizeof(head));memset(dp1,0,sizeof(dp1));
        flag=cnt=maxi=0;memset(dp2,0,sizeof(dp2));
        while(gets(m)!=NULL&&m[0]!='\0'){
            sscanf(m,"%d%d%d",&a,&b,&c);
            add_edge(a,b,c),add_edge(b,a,c);flag=1;
        }
        if(flag==1){
            dfs(1,0);
            printf("%d\n",maxi);
        }if(m[0]!='\0')break;
    }
    return 0;
}
