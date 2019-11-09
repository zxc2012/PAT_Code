#include <bits/stdc++.h>
using namespace std;
struct node {
	int id, best;
	int score[4], rank[4];
};
vector<node> stu;
vector<int> sq;
int flag = -1;
bool cmp1(node a, node b) {
	return a.score[flag] > b.score[flag];
}
int main() {
	int n, m, id;
	scanf("%d %d", &n, &m);
	stu.resize(n);
	sq.resize(n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
		stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]);
	}
	for(flag = 0; flag <= 3; flag++) {
		sort(stu.begin(), stu.end(), cmp1);
		for(int i = 0; i < n; i++) {
			stu[i].rank[flag] = i;
			if(i>0&&stu[i].score[flag] == stu[i-1].score[flag])                
			stu[i].rank[flag] = stu[i-1].rank[flag];
		}
	}
	for(int i = 0; i < n; i++) {
		sq[i]=stu[i].id;
		int minn = n;
		for(int j = 0; j <= 3; j++) {
			if(stu[i].rank[j] < minn) {
				minn = stu[i].rank[j];
			}
		}
		for(int j = 0; j <= 3; j++)
			if(stu[i].rank[j] == minn){
				stu[i].best = j;
				break;
			}
	}
	char c[5] = {'A', 'C', 'M', 'E'};
	for(int i = 0; i < m; i++) {
		scanf("%d", &id);
		int temp = 0;
		for(int j=0;j<n;++j)
		if(sq[j]==id){temp=j+1;break;}
		if(temp) {
			int best = stu[temp-1].best;
			printf("%d %c\n", stu[temp-1].rank[best]+1, c[best]);
		} else {
			printf("N/A\n");
		}
	}
	return 0;
}
