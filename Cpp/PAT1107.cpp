#include<bits/stdc++.h>
using namespace std;
vector<int> father,v;
vector<int> hb(1001,-1);
-
int main(){
    int n,m,i,j,t;
    char cc;
    scanf("%d",&n);
    father.resize(n);
    v.resize(n,0);
    for (i = 0; i < n;++ i)
        father[i] = i;
    for (i = 0; i < n; ++i)
    {
        scanf("%d%c ", &m, &cc);
        for (j = 0; j < m; ++j)
        {
            scanf("%d", &t);
            if (hb[t] != -1)
                uni(i, findf(hb[t]));
            else
            	hb[t] = i;
        }
    }
    //sort(father.begin(),father.end());
    for (i = 0; i < n; ++i)
        v[findf(i)]++;
    sort(v.begin(), v.end(),greater<int>());
    for (i = 0; i < n; ++i)
        if(v[i]==0)
            break;
    printf("%d\n%d",i,v[0]);
    for (j = 1; j < i; ++j)
        printf(" %d",v[j]);
    return 0;
}
