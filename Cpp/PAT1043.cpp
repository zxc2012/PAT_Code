#include <bits/stdc++.h>
using namespace std;
int flag,start;
vector<int> v,pre;
void order(int a,int b) {
	if(a==b) {
		v.push_back(pre[a]);
		//printf("%d over\n",pre[a]);
		return;
	}
	if(a>b)return;
	int i, j;
	if(start==0) {
		for (i = a + 1; i<=b; ++i) {
			if (pre[i] >= pre[a])
				break;
		}
		for (j = b; j>=a+1; --j) {
			if (pre[j] < pre[a])
				break;
		}

	} else if (start == 1) {
		for (i = a + 1; i <= b; ++i) {
			if (pre[i] < pre[a])
				break;
		}
		for (j = b; j >= a + 1; --j) {
			if (pre[j] >= pre[a])
				break;
		}

	}
	//printf("%d %d\n",i,j);
	if (i-j==1) {
		order(a+1, j);
		order(i, b);
	}
	v.push_back(pre[a]);
	//printf("%d 2",pre[a]);
}
int main() {
	int N;
	int i;
	scanf("%d", &N);
	pre.resize(N);
	for (i = 0; i<N; ++i)
		scanf("%d", &pre[i]);
	start=0;
	order(0, N - 1);
	if (v.size()!=N) {
		start=1;
		v.clear();
		//printf("\n");
		order(0, N - 1);
	}
	if (v.size()!=N)	printf("NO");
	else {
		printf("YES\n");
		printf("%d", v[0]);
		for (i = 1; i < v.size(); ++i)
			printf(" %d",v[i]);
	}

	return 0;
}
