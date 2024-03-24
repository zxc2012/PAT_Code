#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
int main(){
   int v,e,i,j,r,c1,c2,m;
   scanf("%d %d",&v,&e);
   g.resize(v+1);
   vector<int> has(v+1,0);
   for(i=0;i<e;++i){
      scanf("%d %d",&c1,&c2);
      g[c1].push_back(c2);
      g[c2].push_back(c1);
   }
   scanf("%d",&m);
   for(i=0;i<m;++i){
      scanf("%d",&c1);
      int sum=0;
      vector<int> temp,tp;
      fill(has.begin(),has.end(),0);
      for(j=0;j<c1;++j){scanf("%d",&c2);has[c2]=1;tp.push_back(c2);}
      for(j=0;j<tp.size();++j){
         temp.clear();
         for(r=0;r<g[tp[j]].size();++r){
            if(has[g[tp[j]][r]]==1)sum++;
            else temp.push_back(g[tp[j]][r]);
         }
      }
      if(sum<c1*(c1-1))printf("Not a Clique\n");
      else{
         int flag=0;
         for(j=0;j<temp.size();++j){
            sum=0;
            for(r=0;r<g[temp[j]].size();++r)
            if(has[g[temp[j]][r]]==1)sum++;
            if(sum==c1){flag=1;break;}
         }
         if(flag==1)printf("Not Maximal\n");
         else printf("Yes\n");
      } 
   }
   return 0; 
}
