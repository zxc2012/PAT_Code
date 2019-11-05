#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int g[501][501],cost[501][501];
vector<int> d, visit,temp,path;
vector<vector<int>> pre;
int min_cost = inf;
int ss;
void dfs(int s,int ct,int dp)
{
    temp[dp] = s;
    if (pre[s].size() == 0)
    {
        if(ct<min_cost){
            min_cost = ct;
            path = temp;
            ss=dp;
        }
    }
    else
        for (int i = 0;i<pre[s].size();++i)
            dfs(pre[s][i],ct+cost[s][pre[s][i]],dp+1);
}
int main()
{
    int n, m, s, D;
    int i, j;
    int c1, c2, dT, c;
    cin >> n >> m >> s >> D;
    d.resize(n,inf);
    pre.resize(n);
    visit.resize(n, 0);
	temp.resize(n, 0);
    fill(g[0],g[0]+501*501,inf);
    for (i = 0;i<m; ++i)
    {
        cin >>c1>>c2>>dT>>c ;
        g[c1][c2] = dT;
        g[c2][c1] = dT;
        cost[c1][c2] = c;
        cost[c2][c1] = c;
    }
    d[s] = 0;
    for (i = 0;i<n; ++i){
        int u = -1, min = inf;
        for (j = 0;j<n; ++j){
            if(visit[j]==0&&d[j]<min){
                u = j;
                min = d[j];
            }
        }
        if(u==-1)
            break;
        visit[u] = 1;
       // printf("\nadd%d",u);
        for (j = 0;j<n; ++j){
            if(visit[j]==0&&g[u][j]<inf){
                if (d[u]+g[u][j]<d[j]){
                    d[j] = d[u] + g[u][j];
                   // printf("\nto%d:%d",j,d[j]);
                    pre[j].clear();
                    pre[j].push_back(u);
                }
                else if(d[u] + g[u][j] == d[j]){
                    pre[j].push_back(u);
                }
            }
        }
    }
    dfs(D,0,0);
    printf("%d", s);
    for (i = ss-1;i>0;--i)
        printf("% d",path[i]);
    printf(" %d %d %d", D,d[D],min_cost);
    return 0;
}