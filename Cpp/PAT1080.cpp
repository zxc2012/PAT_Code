#include<bits/stdc++.h>
using namespace std;
struct Node{
    int grade[2];
    int id;
    vector<int> sc;
};
struct stu{
    int id;
    int grade[2];
    int rank;
};
vector<int> full;
vector<vector<stu>>ans;
vector<Node> sch;
bool cmp(Node& a,Node& b){
    if((a.grade[0]+a.grade[1])!=(b.grade[0]+b.grade[1]))
    return (a.grade[0]+a.grade[1])>(b.grade[0]+b.grade[1]);
    else return a.grade[0]>b.grade[0];
}
bool amp(stu& a,stu& b){
    return a.id<b.id;
}
int main(){
    int n,m,k,i,j;
    cin>>n>>m>>k;
    int g1,g2,a[k];
    full.resize(m);
    ans.resize(m);
    for(i=0;i<m;++i)
    cin>>full[i];
    for(i=0;i<n;++i){
        Node sr;
        cin>>sr.grade[0]>>sr.grade[1];
        for(j=0;j<k;++j){
            cin>>a[k];
            sr.sc.push_back(a[k]);
            sr.id=i;
        }
        sch.push_back(sr);
    }
    sort(sch.begin(),sch.end(),cmp);
    for(i=0;i<sch.size();++i){
        for(j=0;j<k;++j){
            bool y;
            int choice=sch[i].sc[j];
            int x=ans[choice].size();
            if(x>0){
                int last=x-1;
                y=sch[i].grade[0]==ans[choice][last].grade[0]&&sch[i].grade[1]==ans[choice][last].grade[1];
                //printf("\nlast%d %dnow%d %d",xx->grade[0],xx->grade[1],sch[i].grade[0],sch[i].grade[1]);
                x=y?ans[choice][last].rank:x;
            }//ans[sch[i].sc[j]].size()
            if(x<full[choice]||y){
                stu rs;
                rs.id=sch[i].id;
                rs.grade[0]=sch[i].grade[0];
                rs.grade[1]=sch[i].grade[1];
                rs.rank=x;
              //  printf("\nschool%d: %d   ",sch[i].sc[j],rs.rank);
                ans[sch[i].sc[j]].push_back(rs);
                break;
            }
        }
    }
   // printf("\n");
    for(i=0;i<m;++i){
        sort(ans[i].begin(),ans[i].end(),amp);
        for(j=0;j<ans[i].size();++j){
            if(j==0) printf("%d",ans[i][j].id);
            else printf(" %d",ans[i][j].id); 
        }
        printf("\n");
    }
    return 0;
}