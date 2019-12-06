#include<bits/stdc++.h>
using namespace std;
vector<int> tree,temp;
int judge,n;
void dfs(int x,int dp){
    if(x>n)return;
    temp[dp]=tree[x];
    if(x*2>n&&x*2+1>n){
        for(int i=0;i<=dp;++i){
            printf("%d",temp[i]);
            if(i!=0){
                if(judge==1&&temp[i]>temp[i-1])judge=2;
                if(judge==0&&temp[i]<temp[i-1])judge=2;
            }
            if(i!=dp)printf(" ");
        }
        printf("\n");
        return;
    }
    dfs(x*2+1,dp+1);
    dfs(x*2,dp+1);
}
int main(){
    int i;
    scanf("%d",&n);tree.resize(n+1);temp.resize(n+1);
    for(i=1;i<=n;++i)scanf("%d",&tree[i]);
    if(tree[1]>tree[n])judge=1;
    else judge=0;
    dfs(1,0);
    if(judge==2)printf("Not Heap\n");
    else if(judge==1)printf("Max Heap\n");
    else printf("Min Heap\n");
    return 0;
}
