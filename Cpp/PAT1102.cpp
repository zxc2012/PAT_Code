#include <bits/stdc++.h>
using namespace std;
struct Node {
	int index = 0;
	int lchild=-1;
	int rchild=-1;
} node[10];
struct sq {
	int index;
	int data;
};
vector<int> in;
vector<sq> level;
void order(int i,int j) {
	if (node[i].lchild == -1 && node[i].rchild == -1) {
		in.push_back(i);
		return;
	}
	if (node[i].lchild != -1) {
		level.push_back({2 * j,node[i].lchild});
		order(node[i].lchild,2 * j);
	}
	in.push_back(i);
	if (node[i].rchild != -1) {
		level.push_back({2 * j+1,node[i].rchild});
		order(node[i].rchild,2 * j+1);
	}

}
bool cmp(sq a,sq b) {
	return a.index<b.index;
}
int main() {
	int n,i;
	char c1,c2;
	scanf("%d\n", &n);
	for (i = 0; i<n; ++i) {
		if(i==n-1)
			scanf("%c %c", &c1, &c2);
		else
			scanf("%c %c\n", &c1, &c2);
		if(c1<='9'&&c1>='0') {
			node[i].rchild = c1 - '0';
			node[node[i].rchild].index = 1;
		}
		if (c2 <= '9' && c2 >= '0') {
			node[i].lchild = c2 - '0';
			node[node[i].lchild].index = 1;
		}
	}
	for (i = 0; i < n; ++i)
		if(node[i].index==0)
			break;
	level.push_back({1,i});
	order(i,1);
	sort(level.begin(),level.end(),cmp);
	for (i = 0; i < n-1; ++i)
		printf("%d ", level[i].data);
	printf("%d\n", level[n-1].data);
	for (i = 0; i < n - 1; ++i)
		printf("%d ", in[i]);
	printf("%d", in[n - 1]);
	return 0;
}
