#include<bits/stdc++.h>
using namespace std;
struct Node{
    float w;
    float c,d;
};
bool cmp(Node a,Node b){return a.d>b.d;}
int main(){
    int n,k,i;
    cin>>n>>k;
    float sum=0.0;
    vector<Node> v(n);
    for(i=0;i<n;++i)cin>>v[i].w;
    for(i=0;i<n;++i){cin>>v[i].c;v[i].d=v[i].c*100/v[i].w;}
    sort(v.begin(),v.end(),cmp);
    for(i=0;i<n;++i){
        if(v[i].w<=k){
            k-=v[i].w;
            sum+=v[i].c;
        }
        else{
            sum+=v[i].c*k*1.0/v[i].w;
            break;
        } 
    }
    printf("%.2f",sum);
    return 0;
}
