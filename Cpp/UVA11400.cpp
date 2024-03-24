#include<bits/stdc++.h>
using namespace std;
struct Node{
    int v,k,c,l;
}node[1001];
int dp[1005],s[1001];
inline bool cmp(Node a,Node b){return a.v<b.v;}
int main(){
    int n,i,j,x;
	while(~scanf("%d",&n),n){
		dp[0]=s[0]=0;
        for(i=1;i<=n;++i)
            scanf("%d%d%d%d",&node[i].v,&node[i].k,&node[i].c,&node[i].l);
        sort(node+1,node+n+1,cmp);
        for(i=1;i<=n;++i){
            s[i]=s[i-1]+node[i].l;dp[i]=10000000;
            for(j=0;j<i;++j)
            dp[i]=min(dp[i],dp[j]+(s[i]-s[j])*node[i].c +node[i].k);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
