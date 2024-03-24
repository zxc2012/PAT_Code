#include <bits/stdc++.h>
using namespace std;
vector<int> v,t;
int K=0,max_sum=0,lim=0;
void dfs(int n,int k,int p,int sum) {
	for (int i = k<K?t[K-k-1]:lim; i>=1; --i) {
		if(k>1) {
			if(n-k+1>=pow(i,p)) {
				t[K - k] = i;
				dfs(n - pow(i, p), k - 1, p, sum + i);
			}
		}·
		if(k==1) {
			if (n == pow(i, p)) {
				t[K - 1] = i;
				sum += i;
				if(sum>max_sum) {
					max_sum = sum;
					v=t;
				}
				break;
			} else if (n > pow(i, p))
				break;
		}
	}
}
int main() {
	int n, p,i;
	scanf("%d%d%d",&n,&K,&p);
	v.resize(K);
	t.resize(K);
	for(i=1; i<20; i++) {
		if(pow(i,p)<=n-K+1)
			lim=i;
		else break;
	}
	dfs(n,K,p,0);
	if(!max_sum)
		printf("Impossible");
	else {
		printf("%d = ", n);
		for (i = 0; i < K-1; ++i)
			printf("%d^%d + ", v[i],p);
		printf("%d^%d", v[K-1], p);
	}
	return 0;
}