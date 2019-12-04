#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> v,visit,father;
int n;
void dfs(int s) {
    visit[s] = 1;
    for(int i = 1; i<=n; ++i)
	if(g[s][i]==1&&visit[i]==0)dfs(i);
}
int main() {
	int m,sum;
	int i, j,k,c1,c2,r;
	cin >> n >> m >> k;
	g.resize(n+1);
	for (i = 1; i<=n; ++i)
		g[i].resize(n+1,0);
	visit.resize(n+1,0);
	for (i = 0; i < m; ++i) {
		cin >> c1 >> c2;
		g[c1][c2] = 1;
		g[c2][c1] = 1;
	}
	for (i = 0; i < k; ++i) {
		cin >> m;
		v.push_back(m);
	}
	for (i = 0; i < k; ++i) {
		sum = 0;cin >> m;
		fill(visit.begin(),visit.end(),0);
		visit[m] = 1;
		for (j = 1; j<=n; ++j)
			if (visit[j] == 0){
                dfs(j);
                sum++;
            }
		printf("%d\n", sum-1);
	}
	return 0;
}
