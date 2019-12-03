#include<bits/stdc++.h>
using namespace std;
vector<int> father[100001];
map<int,int>u;
vector<int> temp;
int main(){
    int n,m,i,j,r,x,y;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        u[x]=u[y]=1;
        father[x].push_back(y);
        father[y].push_back(x);
    }
    for(i=0;i<m;++i){
        scanf("%d",&x);
        temp.clear();
        int a=0;
        for(j=0;j<x;++j){
            scanf("%d",&y);
            if(u[y]!=0){
                temp.push_back(y);
                for(r=0;r<father[y].size();++r){
                    if(find(temp.begin(),temp.end(),father[y][r])!=temp.end()){
                        printf("No\n");a=1;break;
                    }
                }
            }
            if(a==1)break;
        }
        if(a==0)printf("Yes\n");
    }
    return 0;
}
