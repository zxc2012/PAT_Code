#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
int main(){
    int n,i,j,x,flag=0;
    cin>>n;
    a.resize(10001);
    vector<int> v,vx;
    v.resize(n);
    vx.resize(n);
    for(i=0;i<n;++i){
        cin>>x;
        vx[i]=x;
        a[x].push_back(i);
        if(a[x].size()>1){
            for(j=0;j<a[x].size();++j)
            v[a[x][j]]=1;
        }
    }
    for(i=0;i<n;++i){
        if(v[i]==0){
            printf("%d",vx[i]);flag=1;break;
        }
    }
    if(flag==0)printf("None");
    return 0;
}
