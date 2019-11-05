#include<bits/stdc++.h>
using namespace std;
vector<int> v[100],level[100],sq;
int ind = 0,sum=0;
void dfs(int x,int dp){
    if(sum<dp)
        sum = dp;
    if(v[x][0]!=-1){
        dfs(v[x][0],dp+1);
    }
   // printf("\n%d %d %d",sq[ind],x,dp);
    level[dp].push_back(sq[ind++]);
    if (v[x][1]!=-1)
        dfs(v[x][1], dp + 1);
}
int main(){
    int n,i,j;
    int c1, c2;
    scanf("%d",&n);
    sq.resize(n);
    for (i = 0;i<n; ++i){
        scanf("%d%d", &c1, &c2);
            v[i].push_back(c1);
            v[i].push_back(c2);
    }
    for (i = 0; i < n; ++i)
        scanf("%d",&sq[i]);
    sort(sq.begin(), sq.end());
    dfs(0,0);
    printf("%d",level[0][0]);
    for (i = 1;i<=sum; ++i)
        for (j = 0; j < level[i].size(); ++j)
            printf(" %d", level[i][j]);
        return 0;
}
