#include <bits/stdc++.h>
using namespace std;
const int M=26 * 26 * 26 * 10+1;
vector<int> student[M];
int name2num(char* n){
return (((n[0]-'A')*26*26+(n[1]-'A')*26+n[2]-'A')*10+n[3]-'0');
}
int main() {

	char name[4];
	int n , k ,i=0,j=0; //student course
	int kk = 0;							   //course sequence
	int ss_n;
	scanf("%d%d", &n, &k);
	for (i = 0; i < k; ++i)
	{
		scanf("%d%d", &kk, &ss_n);
		for (j = 0; j < ss_n; ++j)
		{
			scanf("%s", name);
			student[name2num(name)].push_back(kk);
		}
	}
	for (i = 0; i < n; ++i)
	{
		scanf("%s", name);
		printf("%s", name);
		sort(student[name2num(name)].begin(), student[name2num(name)].end());
		printf(" %d", student[name2num(name)].size());
		for (j = 0; j < student[name2num(name)].size(); ++j)
			printf(" %d", student[name2num(name)][j]);
			printf("\n");
	}

	/*first*************/
	return 0;
}
