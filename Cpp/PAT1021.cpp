#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> visit;
vector<int> v,b;
int Max;
void dfs(int s,int dp) {
	int flag=0;
	visit[s] = 1;
    for (int i = 0; i<g[s].size(); ++i) {
		if(visit[g[s][i]]==0) {
			dfs(g[s][i],dp+1);
			flag=1;
		}
	}
	if(flag==0) {
		if(dp>Max) {
			Max = dp;
			v.clear();
			v.push_back(s);
		} else if(dp==Max)
			v.push_back(s);
	}
}
int main() {
	int n;
	int k;
	int i,j,a,b;
	int sum = -1;
	cin >> n;
	g.resize(n + 1);
	visit.resize(n + 1);
	for (i = 1; i<n; ++i) {
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
    for (i = 1; i <= n; ++i)
        if (visit[i] == 0) 
        {
            sum++;
            Max = 0;
            dfs(i, 0);
        }
	if(sum>0)
		printf("Error: %d components",sum+1);
	else {
		fill(visit.begin(), visit.end(), 0);
		k = v[0];
		Max = 0;
		b = v;
        v.clear();
        dfs(k, 0);
		v.insert(v.end(), b.begin(), b.end());
		sort(v.begin(), v.end());
		for (i = 0; i<v.size(); ++i){
            printf("%d\n", v[i]);
            while (i+1 < v.size()&&v[i]==v[i+1])
                    ++i;
        }
	}
	return 0;
}