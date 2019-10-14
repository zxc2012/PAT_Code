#include <bits/stdc++.h>
using namespace std;
set<int> s[50];
void cmp(int a,int b) {
	int num=0,total=s[b].size();
	set<int>::iterator x;
	for (x = s[a].begin(); x != s[a].end(); ++x) {
		if(s[b].find(*x)!=s[b].end())
			++num;
		else total++;
	}
	printf("%0.1f%\n",num*100.0/total);
}
int main() {
	unsigned int N,M,i,j,r,K;//total num,set num,query
	scanf("%d", &N);
	for (i = 0; i<N; ++i) {
		scanf("%d", &M);
		for (j = 0; j < M; ++j) {
			scanf("%d", &r);
			s[i].insert(r);
		}
	}
	scanf("%d", &K);
	for (i = 0; i < K; ++i) {
		scanf("%d%d", &j, &r);
		cmp(j-1,r-1);
	}


	return 0;
}
