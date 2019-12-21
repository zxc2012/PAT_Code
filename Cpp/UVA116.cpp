#include<bits/stdc++.h>
using namespace std;
int n;
inline bool cmp(vector<int>&a,vector<int>&b) {
	int i=0;
	while(i<n-1&&a[i]==b[i])++i;
	return a[i]<b[i];
}
void dfs(int x,vector<vector<int>>& post,vector<int>& v) {
	vector<int> temp(n,0);
	for(int i=0; i<n; ++i) {
		temp[i]=x;
		x=post[i][x];
	}
	if(cmp(temp,v)==1)v=temp;
}
int main() {
	int m,i,j,total;
	while(~scanf("%d%d",&m,&n)) {
		vector<vector<int>>g(m,vector<int>(n,0));
		vector<int> v(n,m-1);
		vector<vector<int>>dp(n,vector<int>(m,0));//colum
		vector<vector<int>>post(n,vector<int>(m,0));//colum
		for(i=0; i<m; ++i)for(j=0; j<n; ++j)scanf("%d",&g[i][j]);
		for(i=0; i<m; ++i)dp[n-1][i]=g[i][n-1];
		for(i=n-2; i>=0; --i)
			for(j=0; j<m; ++j) {
				int x=j-1<0?j-1+m:j-1;
				int y=j+1>m-1?j+1-m:j+1;
				int p[3]= {dp[i+1][j]+g[j][i],dp[i+1][x]+g[j][i],dp[i+1][y]+g[j][i]};
				int sq=*min_element(p,p+3);
				dp[i][j]=sq;
				vector<int>xx;
				if(p[0]==sq)xx.push_back(j);
				if(p[1]==sq)xx.push_back(x);
				if(p[2]==sq)xx.push_back(y);
				post[i][j]=*min_element(xx.begin(),xx.end());
			}
		total=*min_element(dp[0].begin(),dp[0].end());
		for(i=0; i<m; ++i)if(dp[0][i]==total)dfs(i,post,v);
		for(i=0; i<n; ++i) {
			printf("%d",v[i]+1);
			if(i!=n-1)printf(" ");
		}
		printf("\n%d\n",total);
	}
	return 0;
}
