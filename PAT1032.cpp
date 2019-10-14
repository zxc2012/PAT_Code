#include <bits/stdc++.h>
using namespace std;
struct Node{
	int ad;
	int data;
	int next;
} node[100001];
int main() {
	vector<Node> v;
	int s, n, k, i;
	int sq;
	scanf("%d %d %d", &s, &n, &k);
	for (i = 0; i < n;++i)
	{
		scanf("%d ", &sq);
		node[sq].ad = sq;
		scanf("%d %d", &node[sq].data,&node[sq].next);
	}
	sq = 0;
	for (i = s;i!=-1; i =node[i].next)
		{
			v.push_back(node[i]);
			sq++;
		}
	for (auto j=v.begin();j+k<=v.end();j+=k)
		reverse(j,j+k);
	for (i = 0; i < v.size()-1; ++i)
	{
		printf("%05d %d %05d\n", v[i].ad,v[i].data,v[i+1].ad);
	}
	printf("%05d %d -1\n", v[i].ad, v[i].data);
	return 0;
}