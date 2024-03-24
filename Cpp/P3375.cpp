#include<bits/stdc++.h>
using namespace std;
queue<int> q;
struct AC{
    int fail[500010],val[500010],e[500010][26],cnt=0;
    void ins(char* p){
        int len=strlen(p);int j=0;
        for(int i=0;i<len;++i){
            int x=p[i]-'a';
            if(e[j][x]==0)e[j][x]=++cnt;
            j=e[j][x];
        }
        val[j]++;
    }
    void build(){
        for(int i=0;i<26;++i)if(e[0][i])fail[e[0][i]]=0,q.push(e[0][i]);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=0;i<26;++i)
	            if(e[u][i])fail[e[u][i]]=e[fail[u]][i],q.push(e[u][i]);
	            else e[u][i]=e[fail[u]][i];
        }
    }
    int query(char* p){
        int len=strlen(p),j=0,sum=0;
        for(int i=0;i<len;++i){
            int x=p[i]-'a';j=e[j][x];int t=j;
            while(t&&val[t]!=-1)sum+=val[t],val[t]=-1,t=fail[t];
        }
        return sum;
    }
}at;
int n;char s1[1000001];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%s",s1),at.ins(s1);
    at.build();
    scanf("%s",s1);
    printf("%d\n",at.query(s1));
    return 0;
}
