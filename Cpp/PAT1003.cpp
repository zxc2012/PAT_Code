#include <bits/stdc++.h>
using namespace std;
vector<int> visit, team,max_team,sol, d;
vector<vector<int>> g;
const int inf = 1e9;
int main() {
	int n, m, s, t;
	int c1, c2,l;
	int i,j;
	int u,min;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	visit.resize(n,0);
	g.resize(n);
	for (i = 0; i<n; ++i)
		g[i].resize(n,inf);
	d.resize(n,inf);
	sol.resize(n, 0);
	team.resize(n);
	max_team.resize(n);
	for (i = 0; i<n; ++i)
		scanf("%d",&team[i]);
	for (i = 0; i<m; ++i) {
		scanf("%d%d%d", &c1, &c2, &l);
		g[c1][c2] = l;
		g[c2][c1] = l;
	}
	d[s] = 0;
	sol[s] = 1;
	max_team[s] = team[s];
	for (i = 0; i<n; ++i) {
		min=inf;
		u=-1;
        for (j = 0; j < n; ++j)
        if (visit[j] == 0 && d[j] < min)
        {
            u = j;
            min = d[j];
        }
		if(u==-1)break;
		visit[u] = 1;
	//	printf("\nadd%d",u);
		for (j = 0; j<n; ++j)
            if (visit[j] == 0 && g[u][j] < inf)
            {
                if (d[u] + g[u][j] < d[j]) {
					d[j] = d[u] + g[u][j];
					max_team[j] = max_team[u] + team[j];
					sol[j] = sol[u];
					//printf("\n%d->%dlength%dteam%d", u, j, d[j], max_team[j]);
				} else if (d[u] + g[u][j] == d[j]) {
                    if(max_team[u] + team[j] > max_team[j]) 
                    max_team[j] = max_team[u] + team[j];
                    sol[j] += sol[u];
				//	printf("\n%dto%d:%dmax_team%d", u, j, sol[j], max_team[j]);
				}
			}
	}
//	printf("\n");
	printf("%d %d", sol[t], max_team[t]);
	return 0;
}