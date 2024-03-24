#include<bits/stdc++.h>
using namespace std;
struct Node{
int cnum;
string name;
int grade;
};
int c;
bool cmp(Node a,Node b){
    if(c==1){
        return a.cnum<b.cnum;
    }
    else if(c==2){
        if(a.name!=b.name)
        return a.name<b.name;
        else
           return a.cnum<b.cnum;
    }
    else{
        if(a.grade!=b.grade)return a.grade<b.grade;
        else return a.cnum<b.cnum;
    }
}
vector<Node> v;
int main(){
    int n;
    cin>>n>>c;
    int i;
    string s;
    int x,y;
    for(i=0;i<n;++i){
        cin>>x>>s>>y;
        v.push_back({x,s,y});
    }
    sort(v.begin(),v.end(),cmp);
    for(i=0;i<n;++i){
        printf("%06d ",v[i].cnum);
        cout<<v[i].name<<" ";
        printf("%d\n",v[i].grade);
    }
    return 0;
}