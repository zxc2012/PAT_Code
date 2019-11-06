#include <bits/stdc++.h>
using namespace std;
vector<int> v,sq,s;
int main(){
    int n,m,l,i,j;
    int x;
    int max=0;
    cin>>n>>m;
    v.resize(n+1,-1);
    for(i=0;i<m;++i){
	    cin>>x;
	    v[x]=i;
    }
    cin>>l;
    sq.resize(l);
    s.resize(l,1);
    for(i=0;i<l;++i)
    cin>>sq[i];
    for(i=0;i<l;++i)
    {
        for(j=0;j<i;++j){
            if(v[sq[j]]>=0&&v[sq[i]]>=v[sq[j]]&&s[j]+1>s[i])
            s[i]=s[j]+1;
        }
        if(s[i]>max)
        max=s[i];
    }
    printf("%d",max);
    return 0;
}
