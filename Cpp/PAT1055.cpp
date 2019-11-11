#include<bits/stdc++.h>
using namespace std;
struct Node{
    string name;
    int age;
    int w;
};
vector<Node> v;
bool cmp(Node a,Node b){
    if(a.w!=b.w)return a.w>b.w;
    else{
        if(a.age!=b.age)return a.age<b.age;
        else return a.name<b.name;
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    string s;
    int x,y,i,j;
    int mini,maxi;
    for(i=0;i<n;++i){
        cin>>s>>x>>y;
        v.push_back({s,x,y});
    }
    for(i=1;i<=k;++i){
        cin>>x>>mini>>maxi;
        printf("Case #%d:\n",i);
        vector<Node> temp;
        for(j=0;j<n;++j){
            if(v[j].age>=mini&&v[j].age<=maxi)
            temp.push_back(v[j]);
        }
        sort(temp.begin(),temp.end(),cmp);
        if(temp.size()==0)
        printf("None\n");
        else {
            y=temp.size()>x?x:temp.size();
            for(j=0;j<y;++j)
            {
                cout<<temp[j].name;
                printf(" %d %d\n",temp[j].age,temp[j].w);
            }
        }
    }
    return 0;
}