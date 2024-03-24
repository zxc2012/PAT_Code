#include <bits/stdc++.h>
using namespace std;
vector<int> visit,v, g[1001];
int l;
struct Node{
    int var;
    int dp;
};
void bfs(int s,int dp,int r){
    queue<Node> q;
    q.push({s,dp});
    visit[s] = 1;
    while(!q.empty()){
        Node m=q.front();
        q.pop();
        v[r]++;
       // printf("%d(%d)",m.var,m.dp);
        for (int i = 0; i < g[m.var].size(); ++i)
        {
            if (visit[g[m.var][i]] == 0&&m.dp+1<=l)
            {
                visit[g[m.var][i]] = 1;
                q.push({g[m.var][i],m.dp+1});
            }
        }
    }
}
int main(){
    int n;
    scanf("%d%d",&n,&l);
    visit.resize(n + 1, 0);
    v.resize(n + 1, 0);
    int m, i, j,s;
    for (i = 1;i<=n; ++i){
        scanf("%d",&m);
        for (j = 0;j<m; ++j){
            scanf("%d", &s);
            g[s].push_back(i);
        }
    }
    scanf("%d", &m);
    for (i = 1; i <=m; ++i){
        fill(visit.begin(),visit.end(),0);
        scanf("%d", &j);
        //printf("\n");
        bfs(j,0,i);
    }
     // printf("\n");
    for (i = 1; i <= m; ++i)
        printf("%d\n",v[i]-1);
        return 0;
}