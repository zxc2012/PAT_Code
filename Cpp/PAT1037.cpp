#include<bits/stdc++.h>
using namespace std;
vector<int> cm,cp,pm,pp;
int main(){
    int c,p,i,m,sum=0;
    cin>>c;
    for(i=0;i<c;++i){
        cin>>m;
        if(m>0)cp.push_back(m);
        else if(m<0)cm.push_back(m);
    }
    cin>>p;
    for(i=0;i<p;++i){
        cin>>m;
        if(m>0)pp.push_back(m);
        else if(m<0)pm.push_back(m);
    }
    sort(cp.begin(),cp.end());
    sort(pp.begin(),pp.end());
    sort(cm.begin(),cm.end(),greater<int>());
    sort(pm.begin(),pm.end(),greater<int>());
    while(!cp.empty()&&!pp.empty()){
        sum+=*(cp.end()-1)**(pp.end()-1);
        cp.pop_back();
        pp.pop_back();
    }
    while(!cm.empty()&&!pm.empty()){
        sum+=*(cm.end()-1)**(pm.end()-1);
        cm.pop_back();
        pm.pop_back();
    }
    printf("%d",sum);
    return 0;
}