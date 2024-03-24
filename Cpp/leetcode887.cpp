#include<bits/stdc++.h>
using namespace std;
int hp[200], lp[200];
int maxn = 50000;
int main(){
	iota(hp,hp+200,0);
    for (int i = 2;i<200; ++i){
        memcpy(lp, hp, 200 * sizeof(int));
        fill(hp, hp + 200, maxn);
        hp[0]=0,hp[1]=1;
        for (int j = 2; j < 200; ++j){
		    for (int k = 1; k <= j; ++k)
                hp[j] = min(hp[j], max(hp[j-k],lp[k-1])+1);
        	printf("%d %d:%d\n",i,j,hp[j]);
		}

    }

                return 0;
}
