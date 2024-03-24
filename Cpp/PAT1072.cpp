#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
vector<vector<int>> g;
vector<int> visit, d;
int main() {
	int n, m, k, ds;
    int h,r;
    set<int> l;
    int i,j,t;
	int s1, s2;
	int loc = 0, house = inf, sq = inf;
	string c1,c2;
    cin >> n >> m >> k >> ds;
	g.resize(n + 1+m);
	for (i = 1; i<=n+m; ++i)
		g[i].resize(n + 1+m,inf);
	visit.resize(n + 1+m,0);
	d.resize(n + 1+m, inf);
	for (i = 0; i < k; ++i) {
        cin >> c1 >> c2 >> t;
        if (c1[0]=='G'){
            c1 = c1.substr(1);
            s1 = stoi(c1)+n;
        }
        else s1 = stoi(c1);
        if (c2[0] == 'G'){
            c2 = c2.substr(1);
            s2 = stoi(c2)+n;
        }
        else s2 = stoi(c2);
        g[s1][s2] = t;
        g[s2][s1] = t;
	}
    int flag = 0;
    for (t = 1; t<=m; ++t) {
		fill(d.begin(), d.end(), inf);
		fill(visit.begin(), visit.end(), 0);
		d[n + t] = 0;
        h = 0;
        for (i = 1; i <= n + m; ++i) {
			int u = -1;
			int mini = inf;
			for (j = 1; j<= n + m; ++j)
				if(!visit[j]&&d[j]<mini) {
					u=j;
					mini = d[j];
				}
			if(u==-1)
				break;
			visit[u] = 1;
			for (j = 1; j<= n + m; ++j) {
				if(!visit[j]) {
					if (d[u] + g[u][j] <d[j]) {
						d[j] = d[u] + g[u][j];
					} 
				}
			}
		}
        l.clear();
            for (i = 1; i <= n; ++i)
            {
                h += d[i];
                if (d[i] > ds)
                {
                    flag = 1;
                    break;
                }
                else
                    flag = 0;
                l.insert(d[i]);
               // printf("\nG%dto%d:%d ", t, i, d[i]);
            }
            if (flag == 1)
                continue;
            r = *l.begin();
            if (r > loc)
            {
                loc = r;
                house = h;
                sq = t;
            }
            else if (r == loc)
            {
                if (h < house){
                    house = h;
                    sq = t;
                }
                else if (h == house)
                    if (t < sq){
                        sq = t;
                    }
            }
           // printf("\nloc%dhouse%d\n", loc, house);
	}
    if (flag == 1)
        printf("No Solution");
    else{
        printf("G%d\n", sq);
        printf("%.1f %.1f", loc*1.0, house * 1.0 / n /*+ 0.05*/);
    }
	return 0;
}