#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
struct Node{
    float p;//price
    float d;//distance
};
bool cmp(Node a,Node b){return a.d<b.d;}
int main(){
    float c,d,a,n,w=0,left=0;
    int i,j;
    float sum=0.0;
    cin>>c>>d>>a>>n;
    vector<Node> v(n);
    for(i=0;i<n;++i)cin>>v[i].p>>v[i].d;
    sort(v.begin(),v.end(),cmp);
    i=1;
    if(v[0].d>0){printf("The maximum travel distance = %.2f",0);return 0;}
    Node x={v[0].p,0};
    while(w<d){
        Node mini={inf,0};
        if(d-w<=c*a)mini={x.p,d};//first price<last price
        while(i<v.size()&&v[i].d-w<=c*a){
            if(v[i].p<x.p){mini.p=v[i].p;mini.d=v[i].d;j=i;break;}
            else{//find the minimum price
                mini.p=min(v[i].p,mini.p);
                if(v[i].p==mini.p){mini.d=w+c*a;j=i;}
                ++i;
            }
        }
        if(mini.d==0){printf("The maximum travel distance = %.2f",w+c*a);break;}
        else {
                sum+=x.p*(mini.d-w-left)/a;
                //printf("\npass%f %d,add%f*%d",mini.p,v[j].d,x.p,(mini.d-w-left));
                if(mini.d==d){printf("%.2f",sum);break;}
                left=mini.d-v[j].d;
                w=v[j].d;i=j+1;x=mini;
            }
    }
    return 0;
}
