#include<bits/stdc++.h>
using namespace std;
struct Node{
    string card,level,site,date,number;
    int score;
};
struct que{int type=0;string term;};
bool cmp1(Node& a,Node& b){
    if(a.score!=b.score)return a.score>b.score;
    else return a.card<b.card;
}
bool cmp2(que& a,que& b){
    if(a.type!=b.type)return a.type>b.type;
    else return a.term<b.term;
}
vector<Node> v,temp;
int main(){
    int n,m,i,j,x,y;
    scanf("%d%d",&n,&m);
    v.resize(n);
    for(i=0;i<n;++i){
        char s[15];
        scanf("%s %d",s,&x);
        v[i].card=s;
        v[i].level.insert(0,s,1);
        v[i].site.insert(0,s+1,3);
        v[i].date.insert(0,s+4,6);
        v[i].number.insert(0,s+10,3);
        v[i].score=x;
    }
    for(i=0;i<m;++i){
        char s[15];
        scanf("%d %s",&x,s);
        printf("Case %d: %d %s\n",i+1,x,s);
        if(x==1){
            temp.clear();
            for(j=0;j<n;++j)
                if(v[j].level==s)temp.push_back(v[j]);
            sort(temp.begin(),temp.end(),cmp1);
            if(temp.size()==0)printf("NA\n");
            else for(j=0;j<temp.size();++j)printf("%s %d\n",temp[j].card.c_str(),temp[j].score);
        }
        else if(x==2){
            int nt=0,ns=0;
            for(j=0;j<n;++j)
            if(v[j].site==s){nt++;ns+=v[j].score;}
            if(nt==0)printf("NA\n");
            else printf("%d %d\n",nt,ns);
        }
        else if(x==3){
            y=1;
            vector<que> q3;
            unordered_map<string,int>mp;
            for(j=0;j<n;++j)
            if(v[j].date==s){
                if(mp[v[j].site]==0){
                    mp[v[j].site]=y;
                    q3.push_back({1,v[j].site});
                    ++y;
                }
                else q3[mp[v[j].site]-1].type++;
            }
            sort(q3.begin(),q3.end(),cmp2);
            if(y==1)printf("NA\n");
            else for(j=0;j<q3.size();++j)printf("%s %d\n",q3[j].term.c_str(),q3[j].type);
        }
    }
    return 0;
}
