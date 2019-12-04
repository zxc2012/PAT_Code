#include<bits/stdc++.h>
using namespace std;
struct Node{
    string data;
    int l,r;
};
string s="";
vector<Node>v;unordered_map<int,int>father;
string dfs(int x){
    if(x==-1)return "";
//    printf("\n");
//    cout<<v[x].data[0];
    string temp,temp1,temp2;
    if(v[x].l==-1&&v[x].r==-1){
        if(isalnum(v[x].data[0]))temp="("+v[x].data+")";
        else temp=v[x].data;
        return temp;
    }
    temp1=dfs(v[x].l);
    temp2=dfs(v[x].r);
    if(v[x].data=="-")temp="(-"+temp1+temp2+")";
    else temp="("+temp1+temp2+v[x].data+")";
    return temp;
}
int main(){
    int n,i,c1,c2,head;
    scanf("%d",&n);v.resize(n+1);
    for(i=1;i<=n;++i){
        char s[11];getchar();
        scanf("%s %d %d",s,&c1,&c2);
        v[i]={s,c1,c2};
        father[c1]=i;father[c2]=i;
    }
    for(i=1;i<=n;++i)if(father[i]==0)head=i;
    cout<<dfs(head);
    return 0;
}
