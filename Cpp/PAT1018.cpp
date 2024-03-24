#include<bits/stdc++.h>
using namespace std;
vector<int> visit,bike,dx,temp,ans;
vector<vector<int>> g,pre;
const int Inf = 1e9;
int d,bring=Inf,take=Inf,flag=0,sum=0,num=0;
void dfs(int s) {
	visit[s] = 1;
	int i;
	if (pre[s][0] == -1) {
		sum=0;
		num=0;
		temp.insert(temp.begin(),d);
		for (i = temp.size() - 2; i >= 0; --i) {
			sum += bike[temp[i]];
			if(sum<0) {
				num += -sum;
				sum=0;
			}
			//	printf("\nvisit%d sum%d num%d",temp[i],sum,num);
		}
		if(num<bring) {
			bring = num;
			take = sum > 0 ? sum : 0;
			ans = temp;
		}
		if(num==bring) {
			if(sum>0&&sum<take) {
				take = sum;
				ans = temp;
			}
		}
		temp.erase(temp.begin(),temp.begin()+1);
		return;
	} else {
		for (int i = 0; i<pre[s].size(); ++i)
			//if(!visit[pre[s][i]])
		{
			temp.push_back(pre[s][i]);
			dfs(pre[s][i]);
			temp.pop_back();
		}
	}

}
int main() {
	int n, c, m,r;
	int i,j,a,b,cx;
	cin >> c >> n >> d >> m;
	bike.resize(n + 1);
	bike[0] = 0;
	for (i = 1; i<=n; ++i) {
		scanf("%d", &r);
		bike[i] = r - c / 2;
	}
	g.resize(n+1);
	pre.resize(n + 1);
	visit.resize(n + 1, 0);
	dx.resize(n + 1, Inf);
	for (i = 0; i<=n; ++i)
		g[i].resize(n + 1, Inf);
	for (i = 0; i < m; ++i) {
		cin >> a >> b >> cx;
		g[a][b] = cx;
		g[b][a] = cx;
	}
	dx[0] = 0;
	for (i = 0; i <= n; ++i) {
		int u = -1;
		int Min = Inf;
		for (j = 0; j <= n; ++j) {
			if (!visit[j]&&dx[j]<Min) {
				Min = dx[j];
				u = j;
			}
		}
		if(u==-1)
			break;
		visit[u] = 1;
		for (j = 0; j<=n; ++j) {
			if(!visit[j]) {
				if (dx[j] > dx[u] + g[u][j]) {
					dx[j] = dx[u] + g[u][j];
					pre[j].clear();
					pre[j].push_back(u);
				} else if (dx[j] == dx[u] + g[u][j]) {
					pre[j].push_back(u);
				}
			}
		}
	}
	pre[0].push_back(-1);
	dfs(d);
	printf("%d ",bring);
	for (i =ans.size()-1; i>0; --i)
		printf("%d->",ans[i]);
	printf("%d",ans[0]);
	printf(" %d", take);
	return 0;
}
