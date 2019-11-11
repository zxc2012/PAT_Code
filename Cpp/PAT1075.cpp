#include<bits/stdc++.h>
using namespace std;
struct pm{
    int id;
    int p;
    int grade;
};
vector<pm> plist;
vector<int> perfect;
struct Node{
    int id;
    vector<int> grade;//-2
    int index=0;
    int sum=0;
};
vector<Node> nlist;
bool cpm(pm a,pm b){
    if(a.id!=b.id)return a.id<b.id;
    else{
        if(a.p!=b.p)return a.p<b.p;
        else return a.grade>b.grade;
    }
}
bool npm(Node a,Node b){
    if(a.sum!=b.sum)return a.sum>b.sum;
    else{
        if(a.index!=b.index)return a.index>b.index;
        else return a.id<b.id;
    }
}
int main(){
    int n,k,m;
    int x;
    int i,j;
    cin>>n>>k>>m;
    for(i=0;i<k;++i){
        cin>>x;
        perfect.push_back(x);
    }
    int y,z;
    for(i=0;i<m;++i){
        cin>>x>>y>>z;
        plist.push_back({x,y,z});
    }
    sort(plist.begin(),plist.end(),cpm);
    for(i=0;i<plist.size();++i){
        int flag=0;
        Node sr;
        int index=0;
        sr.id=plist[i].id;
        sr.grade.resize(k,-2);
        while(index==0||plist[i].id==plist[i-1].id){
            if(index==0||plist[i].p!=plist[i-1].p){
                sr.grade[plist[i].p-1]=plist[i].grade;
                if(plist[i].grade>=0){
                    flag=1;
                    sr.sum+=plist[i].grade;
                    if(plist[i].grade==perfect[plist[i].p-1]) sr.index++;
                }
                index++;
            }
            i++;
        }
        i--;
        if(flag==1)
        nlist.push_back(sr);
    }
    sort(nlist.begin(),nlist.end(),npm);
    for(i=0;i<nlist.size();++i){
        y=(i==0||nlist[i].sum!=nlist[i-1].sum)?i+1:y;
        printf("%d %05d %d",y,nlist[i].id,nlist[i].sum);
        for(j=0;j<k;++j){
            if(nlist[i].grade[j]<0){
                if(nlist[i].grade[j]==-2) printf(" -");
                else printf(" 0");
            }
            else printf(" %d",nlist[i].grade[j]);
        }
        printf("\n");
    }
    return 0;
}