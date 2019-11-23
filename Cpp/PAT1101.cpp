#include<bits/stdc++.h>
using namespace std;
vector<int> temp,da,v;
int main(){
    int n,i,maxi=0,mini=2e9;
    cin>>n;
    v.resize(n);
    for(i=0;i<n;++i){
        scanf("%d",&v[i]);
        maxi=max(v[i],maxi);
        da.push_back(maxi);
    }
    for(i=n-1;i>=0;--i){
        mini=min(v[i],mini);
        if(v[i]==mini&&mini==da[i])temp.push_back(mini);
    }
    printf("%d\n",temp.size());
    sort(temp.begin(),temp.end());
    for(i=0;i<temp.size();++i){
        printf("%d",temp[i]);
        if(i!=temp.size()-1)printf(" ");
    }
    cout<<endl;
    return 0;
}
