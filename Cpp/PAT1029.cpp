#include<bits/stdc++.h>
using namespace std;
vector<int> v[2],temp;
int main(){
    int n[2],i,j;
    for(i=0;i<2;++i){
        cin>>n[i];v[i].resize(n[i]);
        for(j=0;j<n[i];++j)
        cin>>v[i][j];
        sort(v[i].begin(),v[i].end());
    }
    i=0,j=0;
    while(i<n[0]&&j<=n[1]||i<=n[0]&&j<n[1]){
        if(v[0][i]<=v[1][j]&&i<n[0]||j==n[1]){temp.push_back(v[0][i]);++i;}
        else if(v[0][i]>v[1][j]&&j<n[1]||i==n[0]){temp.push_back(v[1][j]);++j;}
    }
    if(temp.size()%2==0)printf("%d",temp[temp.size()/2-1]);
    else printf("%d",temp[(temp.size()+1)/2-1]);
    return 0;
}
