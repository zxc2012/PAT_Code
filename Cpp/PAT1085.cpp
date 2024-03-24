#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,sum=0;;
    long long int p;
    scanf("%d%lld",&n,&p);
    vector<long long int> v(n);
    for(i=0;i<n;++i)scanf("%lld",&v[i]);
    sort(v.begin(),v.end());
    for(auto it=v.begin();it!=v.end();++it){
        sum=max(sum,(int)(upper_bound(it+sum,v.end(),p**it)-it));
    }
    printf("%d",sum);
    return 0;
}
