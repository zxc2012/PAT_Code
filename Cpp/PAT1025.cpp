#include<bits/stdc++.h>
using namespace std;
struct Node{
    long long int cnum;
    int rank[3];
    int grade;
};
vector<Node> v;
bool cmp(Node a,Node b){
    if(a.grade!=b.grade)
    return a.grade>b.grade;
    else return a.cnum<b.cnum;
}
int main(){
    int n,k;
    cin>>n;
    int i,j,x;
    int index=0;
    long long int c;
    for(i=1;i<=n;++i){
        cin>>k;
        for(j=0;j<k;++j){
            scanf("%lld %d",&c,&x);
            Node y;
            y.cnum=c;
            y.grade=x;
            y.rank[1]=i;
            v.push_back(y);
            index++;
        }
        sort(v.begin()+index-k,v.begin()+index,cmp);
        for(j=index-k;j<index;++j){
            v[j].rank[2]=j-index+k+1;
            if(j>index-k&&v[j].grade==v[j-1].grade)
            v[j].rank[2]=v[j-1].rank[2];
        }
    }
    sort(v.begin(),v.end(),cmp);
    printf("%d\n",index);
    for(j=0;j<index;++j){
        v[j].rank[0]=j+1;
        if(j>0&&v[j].grade==v[j-1].grade)
        v[j].rank[0]=v[j-1].rank[0];
        printf("%013lld %d %d %d\n",v[j].cnum,v[j].rank[0],v[j].rank[1],v[j].rank[2]);
    }
    return 0;
}