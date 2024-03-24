#include <cstdio>
#include <set>
using namespace std;
set<int> a;
const int maxn = 10010;
int m, n, pre[maxn], u, v;
 
int main(){
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; i++){
		scanf("%d", pre+i);
		a.insert(pre[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		int flagv = 0, flagu = 0;
		if(a.find(u) == a.end())
			flagu = 1;
		if(a.find(v) == a.end())
			flagv = 1;
		if(flagv || flagu){
			if(flagv&flagu)
				printf("ERROR: %d and %d are not found.\n", u, v);
			else if(flagv)
				printf("ERROR: %d is not found.\n", v);
			else
				printf("ERROR: %d is not found.\n", u);
		}else{
			int MAX = max(u, v), MIN = min(u, v);
			for(int i = 0; i < n; i++){
				if(pre[i] == u){
					printf("%d is an ancestor of %d.\n", u, v);
					break;
				}else if(pre[i] == v){
					printf("%d is an ancestor of %d.\n", v, u);
					break;
				}
				else if(pre[i] > MIN && pre[i] < MAX){
					printf("LCA of %d and %d is %d.\n", u, v, pre[i]);
					break;
				}
			}
		}
	}
	return 0;
}