#include <bits/stdc++.h>
using namespace std;
vector<int> sq,in;
void downadjust(int l,int h) {
	int i = l, j = l * 2;
	while(j<=h) {
		if(j+1<=h&&in[j+1]>in[j])
			j++;
		if(in[j]>in[i]) {
			swap(in[i],in[j]);
			i = j;
			j *= 2;
		} else
			break;
	}
}
int main() {
	int n,i,j;
	scanf("%d",&n);
	sq.resize(n+1);
	in.resize(n+1);
	for (i = 1; i<=n; ++i)
		scanf("%d",&sq[i]);
	for (i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	for (i = 1; in[i] <= in[i + 1]; ++i);
	j = i;
	for (; sq[i] <= in[i]; ++i);
	if(i>n)
	{
		printf("Insertion Sort\n");
		sort(sq.begin() + 1, sq.begin() + j+2);
		printf("%d", sq[1]);
		for (i = 2; i <= n; ++i)
			printf(" %d", sq[i]);
	}
	else{
		printf("Heap Sort\n");
		for (i = n; i > 0; i--)
			if(in[i]<in[1])
				break;
		swap(in[1],in[i]);
		downadjust(1,i-1);
		printf("%d",in[1]);
		for (i = 2; i <= n; ++i)
			printf(" %d", in[i]);
	}
	return 0;
}
