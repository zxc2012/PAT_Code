#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g,pre;
vector<int> visit, d, w,temp,ans,num;
const int inf = 1e9;
int sum, total = 0;
float av = 0;
void dfs(int s,int dp) {
	int i;
	sum += w[s];
	temp.push_back(s);
	if (pre[s][0] == -1) {
		if(sum>total) {
			total = sum;
			av = total *1.0/ dp;
			ans = temp;
		} else if(sum==total) {
			if (total * 1.0 / dp>av) {
				av = total * 1.0 / dp;
				ans = temp;
			}
		}

	} else {
		for (i = 0; i<pre[s].size(); ++i)
			dfs(pre[s][i], dp + 1);
	}
	sum -= w[s];
	temp.pop_back();
}
int main() {
	int n, k;
	map<string, int> name2int;
	map<int, string> int2name;
	string s;
	string s1, s2;
	int c1, c2;
	int i, j;
	int t,dt;
	cin >> n >> k >> s;
	g.resize(n+1);
	pre.resize(n + 1);
    num.resize(n + 1);
    visit.resize(n + 1, 0);
	d.resize(n + 1, inf);
	w.resize(n + 1);
	for (i = 1; i<=n; ++i)
		g[i].resize(n+1,inf);
	name2int[s] = 1;
	int2name[1] = s;
	for (i = 2; i<=n; ++i) {
		cin >> s1 >> t;
		if(s1=="ROM")
			dt = i;
		name2int[s1] = i;
		int2name[i] = s1;
		w[i] = t;
	}
	for (i = 0; i<k; ++i) {
		cin >> s1 >> s2 >> t;
		c1 = name2int[s1];
		c2 = name2int[s2];
		g[c1][c2] = t;
		g[c2][c1] = t;
	}
	d[1] = 0;
	num[1] = 1;
	pre[1].push_back(-1);
	for (i = 1; i<=n; ++i) {
		int u = -1;
		int min = inf;
		for (j = 1; j<=n; ++j)
			if(!visit[j]&&d[j]<min) {
				u = j;
				min = d[j];
			}
		if(u==-1)
			break;
		visit[u] = 1;
		for (j = 1; j<=n; ++j) {
			if(!visit[j]) {
				if(d[u]+g[u][j]<d[j]) {
					d[j] = d[u] + g[u][j];
					num[j] = num[u];
					pre[j].clear();
					pre[j].push_back(u);
				} else if (d[u] + g[u][j] == d[j]) {
					pre[j].push_back(u);
					num[j] += num[u];
				}
			}
		}
	}
	dfs(dt,0);
	printf("%d %d %d %d\n",num[dt],d[dt],total,(int)av);
	cout << s;
	for (i = ans.size() - 2; i>=0; --i)
		cout <<"->"<< int2name[ans[i]];
	return 0;
}
