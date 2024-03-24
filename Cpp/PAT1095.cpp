#include<bits/stdc++.h>
using namespace std;
struct Node{
    string number;
    int clock[3];
    int time;
    int status;
};
vector<Node> v,st;
map<string,int> m; 
bool cmp1(Node& a,Node& b){
    if(a.number!=b.number) return a.number<b.number;
    else return a.time<b.time;
}
bool cmp2(Node& a,Node& b){return a.time<b.time;}
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
    int n,k,i,j,ma;
    cin>>n>>k;
    int c[3];
    int x;
    for(i=1;i<=n;++i){
    	string s,ss;
        cin>>s;
        scanf("%d:%d:%d",&c[0],&c[1],&c[2]);
        cin>>ss;
        if(ss[0]=='i')x=0;else x=1;
        v.push_back({s,{c[0],c[1],c[2]},cal(c),x});
    }
    sort(v.begin(),v.end(),cmp1);
    for(i=0;i<v.size();++i){
        if(v[i].number==v[i+1].number&&v[i].status==0&&v[i+1].status==1){
            st.push_back(v[i]);st.push_back(v[i+1]);
            m[v[i].number]+=v[i+1].time-v[i].time;
            ma=max(m[v[i].number],ma);
        }
    }
    sort(st.begin(),st.end(),cmp2);
    int temp=0,sum=0;
    for(i=0;i<k;++i){
        scanf("%d:%d:%d",&c[0],&c[1],&c[2]);
        for(j=temp;st[j].time<=cal(c)&&j<st.size();++j)
            if(st[j].status==0)sum++;
            else sum--;
        temp=j;
        printf("%d\n",sum);
    }
    for(auto it:m){
        if(it.second==ma)
        cout<<it.first<<" ";
    }
    transfer(ma);
    return 0;
}