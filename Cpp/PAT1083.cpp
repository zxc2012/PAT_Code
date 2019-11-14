#include<bits/stdc++.h>
using namespace std;
struct Node{
	char name[11];
	char ID[11];
	int grade;
};
vector<Node> v;
bool cmp(Node& a,Node& b){
    return a.grade>b.grade;
}
int main(){
    int n,i;
    cin>>n;
    getchar();
    int l,m;
    for(i=0;i<n;++i){
        Node y;
        scanf("%s %s %d",y.name,y.ID,&y.grade);
        getchar();
        v.push_back(y);
    }
    sort(v.begin(),v.end(),cmp);
    cin>>l>>m;
    int flag=0;
    for(i=0;i<v.size();++i){
        if(v[i].grade>=l&&v[i].grade<=m){
            flag=1;
            printf("%s %s\n",v[i].name,v[i].ID);
        }
    }
    if(flag==0)printf("NONE\n");
    return 0;
}
