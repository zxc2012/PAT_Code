#include<bits/stdc++.h>
using namespace std;
vector<int> v;
void transfer(int a,int b)
{
    v.push_back(a%b);
    if(a/b==0)return;
    else transfer(a/b,b);
}
int main(){
    int n,b,flag=0;
    int i;
    cin>>n>>b;
    transfer(n,b);
    for(i=0;i<=v.size()/2;++i)
    if(v[i]!=v[v.size()-1-i]){
    flag=1;
    break;
    }
    if(flag==1)printf("No\n");
    else printf("Yes\n");
    for(i=v.size()-1;i>0;--i)
    printf("%d ",v[i]);
    printf("%d",v[0]);
    return 0;
}
