#include<bits/stdc++.h>
using namespace std;
struct Node{
    int b,e;
};
vector<int> v,sum;
vector<Node> temp;
const int inf=1e9;
int main(){
    int n,m,i,j,mini=inf,x=0;
    cin>>n>>m;
    v.resize(n);sum.resize(n+1);
    sum[0]=0;
    for(i=0;i<n;++i){scanf("%d",&v[i]);x+=v[i];sum[i+1]=x;}
    for(auto it=sum.begin();it!=sum.end()-1;++it){//begin
        auto j=lower_bound(it,sum.end(),*it+m);
        if(j!=sum.end()){
            if(*j-*it<mini){
                mini=*j-*it;
                temp.clear();
                temp.push_back({(int)(it-sum.begin()),(int)(j-sum.begin())});
            }
            else if(*j-*it==mini)temp.push_back({(int)(it-sum.begin()),(int)(j-sum.begin())});
            //printf("\nsq%d--%d sum%d--sum%d",(int)(it-sum.begin()),(int)(j-sum.begin()),*it,*j);
        }
    }
    for(i=0;i<temp.size();++i)printf("%d-%d\n",temp[i].b+1,temp[i].e);
    return 0;
}
