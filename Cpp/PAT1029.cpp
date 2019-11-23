#include<bits/stdc++.h>
using namespace std;
vector<int> v[2],temp;
int main(){
    int n[2],i,j;
    for(i=0;i<2;++i){
        scanf("%d",&n[i]);v[i].resize(n[i]);
        for(j=0;j<n[i];++j)
        scanf("%d",&v[i][j]);
        //sort(v[i].begin(),v[i].end());
    }
    i=0,j=0;
    while(i<n[0]&&j<n[1]){
        if(v[0][i]<=v[1][j]){temp.push_back(v[0][i]);++i;}
        else {temp.push_back(v[1][j]);++j;}
        if(temp.size()==(n[0]+n[1]+1)/2)printf("%d",temp.back());
    }
    while(i<n[0]){
        temp.push_back(v[0][i]);++i;
        if(temp.size()==(n[0]+n[1]+1)/2)printf("%d",temp.back());
    }
    while(j<n[1]){
        temp.push_back(v[1][j]);++j;
        if(temp.size()==(n[0]+n[1]+1)/2)printf("%d",temp.back());
    }
    return 0;
}
