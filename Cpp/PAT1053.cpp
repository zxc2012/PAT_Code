#include <bits/stdc++.h>
using namespace std;
struct Node {
	int w;
	int k=0;
	int child[100] = {-1};
} node[100];
int sum;
int S;
vector<int> temp;
bool cmp(int a,int b) {
	return node[a].w < node[b].w;
}
void find(Node x,int k) {
	if (k == 0) {
		if (sum == S) {
			printf("%d", temp[0]);
			for (int j = 1; j < temp.size(); ++j)
				printf(" %d", temp[j]);
			printf("\n");
		} else
			return;
	}
	sort(x.child, x.child + k, cmp);
	for (int i = k - 1; i >= 0; --i) {
		temp.push_back(node[x.child[i]].w);
		sum+=node[x.child[i]].w;
		// printf("%d %d\n", node[x.child[i]].w,sum);
		find(node[x.child[i]],node[x.child[i]].k);
		temp.pop_back();
		sum-=node[x.child[i]].w;
	}

}
int main() {
	int N, M;
	int i,j;
	int start;
	scanf("%d%d%d", &N, &M, &S);
	for (i = 0; i<N; ++i)
		scanf("%d",&node[i].w);
	for (i = 0; i < M; ++i) {
		scanf("%d", &start);
		scanf("%d", &(node[start].k));
		for (j = 0; j < node[start].k; ++j)
			scanf("%d",&(node[start].child[j]));
	}
	temp.push_back(node[0].w);
	sum = node[0].w;
	find(node[0],node[0].k);
	return 0;
}
