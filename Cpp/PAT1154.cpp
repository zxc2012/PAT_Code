#include<bits/stdc++.h>
using namespace std;
vector<int> color;
vector<vector<int>> ver;
int main(){
    int v,e,k,i,j,r,c1,c2;
    scanf("%d%d",&v,&e);
    ver.resize(v);color.resize(v);
    for(i=0;i<e;++i){
        scanf("%d%d",&c1,&c2);
        ver[c1].push_back(c2);
        ver[c2].push_back(c1);
    }
    scanf("%d",&k);
    for(i=0;i<k;++i){
        int flag=0,x=0;
        unordered_map<int,int>mp;
        for(j=0;j<v;++j){
            scanf("%d",&color[j]);
            if(mp[color[j]]==0){mp[color[j]]=1;x++;}
        }
        for(j=0;j<v;++j){
            for(r=0;r<ver[j].size();++r)
            if(color[ver[j][r]]==color[j]){printf("No\n");flag=1;break;}
            if(flag==1)break;
        }
        if(flag==0)printf("%d-coloring\n",x);
    }
    return 0;
}
