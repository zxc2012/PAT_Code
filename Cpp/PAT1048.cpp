#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,i,j,x=0;
    cin>>n>>k;
    vector<int> v(n);
    for(i=0;i<n;++i)
    cin>>v[i];
    sort(v.begin(),v.end());
    i=0,j=n-1;
    while(i<n&&j>i){
        if(v[i]+v[j]<k)++i;
        else if(v[i]+v[j]>k)--j;
        else {x=1;break;}
    }
    if(x=1&&j!=i)
    printf("%d %d",v[i],v[j]);
    else printf("No Solution");
    return 0;
}
