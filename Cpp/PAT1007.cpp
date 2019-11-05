#include <bits/stdc++.h>
using namespace std;
vector<int> v,ed,sol,first;
const int inf=1e9;
int main(){
    int k,i,s;
    cin>>k;
    v.resize(k);
    ed.resize(k);
    first.resize(k);  
    for(i=0;i<k;++i)
    scanf("%d",&v[i]);
    ed[0]=v[0];
    first[0]=v[0];
    for(i=1;i<k;++i){
        if(ed[i-1]+v[i]>v[i]){
        ed[i]=ed[i-1]+v[i];
        first[i]=first[i-1];
        }
        else{
        ed[i]=v[i];
        first[i]=v[i];
        }
    }
    int max=-inf;
    for(i=0;i<k;++i){
            if(ed[i]>max){
            max=ed[i];
            sol.clear();
            sol.push_back(i);
            }
    }
    if(max<0){
        printf("0 %d %d",v[0],v[k-1]);
    }
    else{
        s=sol[0];
       printf("%d %d %d",max,first[s],v[s]) ;
    }
    return 0;
}