#include <bits/stdc++.h>
#define ll long long
#define inf 50000000
#define re register
using namespace std;
struct po
{
    int from,to,dis,nxt,cap;
}edge[250001];
int head[250001], cur[1000001], dep[60001], n, m, s, t, u, num = -1, x, y, l, tot, sum, k, fa[10001];
int dis[5001], b[5001], xb[5001], flow[5001]; 
inline void add_edge(int from,int to,int cap,int dis)
{
    edge[++num].nxt = head[from]; 
    edge[num].from=from;
    edge[num].to=to;
    edge[num].cap=cap;
    edge[num].dis=dis;
    head[from]=num;
}
inline void add(int from,int to,int cap,int dis)
{
    add_edge(from,to,cap,dis);
    add_edge(to,from,0,-dis);
}
inline bool spfa()
{
    memset(dis,100,sizeof(dis));
    memset(b,0,sizeof(b));
    queue<int> q;
    while(!q.empty())
    q.pop();
    for(re int i=1;i<=n;i++)
    {
        fa[i]=-1;
    }
    b[s]=1;dis[s]=0;fa[s]=0;
    flow[s]=inf;q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        b[u] = 0; 
        for(re int i=head[u];i!=-1;i=edge[i].nxt)
        {
            int v=edge[i].to;
            
            if (edge[i].cap > 0 && dis[v] > dis[u] + edge[i].dis) 
            {
                dis[v]=dis[u]+edge[i].dis;
                fa[v]=u;
                xb[v]=i;
                flow[v]=min(flow[u],edge[i].cap);
                if(!b[v]){b[v]=1,q.push(v);}
            }
        }
    }
    return dis[t]<inf;
}
inline void max_flow()
{
    while(spfa())
    {
        int k=t;
        while(k!=s)
        {
            edge[xb[k]].cap-=flow[t];
            edge[xb[k]^1].cap+=flow[t];
            k=fa[k];
        }
        tot+=flow[t];
        sum += flow[t] * dis[t]; 
    }
}
int main()
{
    memset(head,-1,sizeof(head));
    s=0,t=100;
    ll T[50];
    cout << "请输入六组值:t10 t12 t14 t16 t18 t2\n";
    cin>>T[10]>>T[12]>>T[14]>>T[16]>>T[18]>>T[20];
    for(int i=10;i<=20;i+=2){
        add(s,i,T[i],0);
        for(int j=i+2;j<=20;j+=2){
            add(i,j,inf,200+(j-i-2)*20);
        }
        add(i,23,inf,200+(23-i-2)*20);
        if(i<=14)
            add(i,t,100,0);
        else
            add(i,t,150,0);
    }
    add(23,t,inf,0);
    max_flow();
    cout << "Min Cost:\n";
    cout<<sum<<endl;
    system("pause");
}
