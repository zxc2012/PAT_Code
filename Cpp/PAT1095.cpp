#include<bits/stdc++.h>
using namespace std;
struct Node{
    string number;
    int clock[3];
    int status;
};
struct ind{
    int index;
    int value=0;
};
vector<vector<Node>> v;
map<string,int> m; 
vector<ind> cp;
bool cmp(Node& a,Node& b){
    if(a.clock[0]!=b.clock[0]) return a.clock[0]<b.clock[0];
    else{
        if(a.clock[1]!=b.clock[1])return a.clock[1]<b.clock[1];
        else{
            if(a.clock[2]!=b.clock[2])return a.clock[2]<b.clock[2];
            else return a.status<b.status;
        }
    }
}
bool cm(ind& a,ind& b){
    return a.value>b.value;
}
int cal(int* a){
    return (3600*a[0]+60*a[1]+a[2]);
}
void transfer(int& a){
    int h,m,s;
    h=a/3600;
    m=a/60%60;
    s=a%60;
    printf("%02d:%02d:%02d",h,m,s);
}
int main(){
    int n,k,i,j,r;
    cin>>n>>k;
    int c[3];
    int x;
    for(i=1;i<=n;++i){
    	string s,ss;
        cin>>s;
        scanf("%d:%d:%d",&c[0],&c[1],&c[2]);
        cin>>ss;
        if(ss[0]=='i')x=0;
        else x=1;
        if(m[s]==0){
            m[s]=i;
            vector<Node> sr;
            sr.push_back({s,{c[0],c[1],c[2]},x});
            v.push_back(sr);
        }
        else{
            v[m[s]-1].push_back({s,{c[0],c[1],c[2]},x});
        }
    }
    for(i=0;i<m.size();++i){
        sort(v[i].begin(),v[i].end(),cmp);
    }
    cp.resize(m.size());
    for(j=0;j<m.size();++j){
        for(r=0;r<v[j].size();++r)
        if(v[j][r].status==0){
            if(v[j][r+1].status==1){
                cp[j].index=j;
                if(cal(v[j][r+1].clock)-cal(v[j][r].clock)>0){
                    cp[j].value+=(cal(v[j][r+1].clock)-cal(v[j][r].clock));
                }
            }
        }
    }
    for(i=0;i<k;++i){
        int sum=0;
        scanf("%d:%d:%d",&c[0],&c[1],&c[2]);
        for(j=0;j<m.size();++j){
            int temp=0;
            for(r=0;r<v[j].size();++r)
            if(v[j][r].status==0){
                if(v[j][r+1].status==1){
                    cp[j].index=j;
                    if(temp==0&&cal(v[j][r].clock)<=cal(c)&&cal(c)<cal(v[j][r+1].clock)){
                        sum++;
                        temp=1;
                    }
                }
            }
        }
        printf("%d\n",sum);
    }
    sort(cp.begin(),cp.end(),cm);
    for(i=0;i<cp.size();++i){
        if(cp[i].value==cp[0].value)
        cout<<v[cp[i].index][0].number<<" ";
    }
    transfer(cp[0].value);
    return 0;
}
