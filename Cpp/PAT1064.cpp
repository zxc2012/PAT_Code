#include <bits/stdc++.h>
using namespace std;
int r[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
vector<int> v,temp[10];
int lg(int a)
{
    int temp = 1;
    for (int i = 0;i<11; ++i){
        if(temp>a)
            return i;
        else if (temp == a)
            return i+1;
        else
            temp *= 2;
    }
}
void dfs(int start,int num,int dp){
    if(num<1)
        return;
    int d = lg(num);
    if(num-r[d-1]+1<=r[d-2]){
        temp[dp].push_back(start + num- r[d - 1] / 2);
        dfs(start, num-r[d-1]/2, dp + 1);
        dfs(start + num + 1 - r[d - 1] / 2, r[d-1]/2-1, dp + 1);
    }
    else{
        temp[dp].push_back(start + r[d - 1]-1);
        dfs(start, r[d - 1]-1, dp + 1);
        dfs(start + r[d - 1], num-r[d-1], dp + 1);
    }
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    v.resize(n);
    for (i = 0;i<n; ++i)
        scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    dfs(0, n, 0);
    printf("%d",v[temp[0][0]]);
    for (i = 1;i<lg(n); ++i)
        for (j = 0; j < temp[i].size(); ++j)
            printf(" %d",v[temp[i][j]]);
            return 0;
}
