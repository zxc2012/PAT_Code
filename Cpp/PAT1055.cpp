#include<bits/stdc++.h>
using namespace std;
struct Node{
    char name[9];
    int age;
    int w;
};
vector<Node> v;
bool cmp(Node a,Node b){
    if(a.w!=b.w)return a.w>b.w;
    else{
        if(a.age!=b.age)return a.age<b.age;
        else return (strcmp(a.name,b.name)<0);
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    char s[10];
    int x,y,i,j;
    int mini,maxi;
    for(i=0;i<n;++i){
        Node m;
        scanf("%s %d %d",m.name,&m.age,&m.w);
        v.push_back(m);
    }
    sort(v.begin(),v.end(),cmp);
    for(i=1;i<=k;++i){
        cin>>x>>mini>>maxi;
        printf("Case #%d:\n",i);
        int index=0;
        vector<Node> temp;
        for(j=0;j<n&&index<x;++j){
            if(v[j].age>=mini&&v[j].age<=maxi&&index<x){
                temp.push_back(v[j]);
                index++;
            }
        }
        if(temp.size()==0)
        printf("None\n");
        else {
            for(j=0;j<temp.size();++j)
            {
                printf("%s",temp[j].name);
                printf(" %d %d\n",temp[j].age,temp[j].w);
            }
        }
    }
    return 0;
}