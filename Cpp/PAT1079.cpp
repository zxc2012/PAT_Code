#include <bits/stdc++.h>
using namespace std;
struct Node {
	vector<int> child;
	double sp = 0;
};
vector<Node> v;
vector<double> pw;
double sum=0.0;
double p, r;
void dfs(int x,int dp) {
	int i;
	if(v[x].child.size()!=0) {
		for (i = 0; i<v[x].child.size(); ++i) {
			if (dp+1 > pw.size()-1)
				pw.push_back(pow(r, dp+1));
			dfs(v[x].child[i],dp+1);
		}
	} else {
				sum += 1.0*v[x].sp*p*pw[dp];
				return;
	}
}
int main() {
	int n,i,j;
	int k;
	scanf("%d%lf%lf",&n,&p,&r);
	v.resize(n);
	r=1+r/100.0;
	pw.push_back(1.0);
	for (i = 0; i<n; ++i) {
		scanf("%d",&k);
		if(k==0) {
			scanf("%lf", &v[i].sp);
		} else {
			v[i].child.resize(k);
			for (j = 0; j<k; ++j)
				scanf("%d", &v[i].child[j]);
		}

	}
	dfs(0,0);
	printf("%.1lf",sum);
	return 0;
}

