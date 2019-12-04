#include<bits/stdc++.h>
using namespace std;
struct Node{int data=-1,next=-1;}node[100001];
vector<int> l1,l2,sh,lo;
int main(){
    int ad1,ad2,n,x,i;
    scanf("%d%d%d",&ad1,&ad2,&n);
    for(i=0;i<n;++i){
        scanf("%d",&x);
        scanf("%d%d",&node[x].data,&node[x].next);
    }
    for(x=ad1;x!=-1;x=node[x].next)l1.push_back(x);
    for(x=ad2;x!=-1;x=node[x].next)l2.push_back(x);
    sh=l1.size()<l2.size()?l1:l2;lo=l1.size()<l2.size()?l2:l1;
    x=sh.size()-1;
    for(i=0;i<lo.size();++i){
        printf("%05d %d ",lo[i],node[lo[i]].data);
        if((i+1)%2==0){
            if(sh[x]==-1)printf("-1\n");
            else printf("%05d\n",sh[x]);
            if(x>=0)
            printf("%05d %d ",sh[x],node[sh[x]].data);
            --x;
        }
        if(node[lo[i]].next==-1)printf("-1\n");
        else printf("%05d\n",node[lo[i]].next);
    }
    return 0;
}
