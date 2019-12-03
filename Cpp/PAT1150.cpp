#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
vector<vector<int>>g;
struct Node{int sq,sum;};
vector<Node>v;
bool cmp(Node a,Node b){return a.sum<b.sum;}
int main(){
    int n,m,i,j,c1,c2,x,y,sum,flag=0,start;
    scanf("%d%d",&n,&m);
    g.resize(n+1);vector<int> temp(n+1);
    for(i=0;i<n+1;++i)g[i].resize(n+1,inf);
    for(i=0;i<m;++i){
        scanf("%d%d%d",&c1,&c2,&x);
        g[c1][c2]=x;
        g[c2][c1]=x;
    }
    scanf("%d",&x);
    for(i=1;i<=x;++i){
        scanf("%d",&c1);
        y=-1,sum=0,flag=0;
        fill(temp.begin(),temp.end(),0);
        for(j=0;j<c1;++j){
            scanf("%d",&c2);
            temp[c2]++;
            if(y==-1){y=c2;start=c2;}
            else{
                sum+=g[y][c2];
                if(g[y][c2]==inf)break;
                y=c2;
            }        
        }
        y=0;
        if(sum>=inf){printf("Path %d: NA (Not a TS cycle)\n",i);continue;}
        for(j=1;j<=n;++j){
            if(temp[j]==0||temp[start]<2){printf("Path %d: %d (Not a TS cycle)\n",i,sum);flag=1;break;}
            else if(temp[j]>1)y++;
        }
        if(flag==1)continue;
        v.push_back({i,sum});
        if(y>1)printf("Path %d: %d (TS cycle)\n",i,sum);
        else printf("Path %d: %d (TS simple cycle)\n",i,sum);
    }
    auto xx=min_element(v.begin(),v.end(),cmp);
    printf("Shortest Dist(%d) = %d",xx->sq,xx->sum);
    return 0;
}
