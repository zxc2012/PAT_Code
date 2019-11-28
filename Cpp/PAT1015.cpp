#include<bits/stdc++.h>
using namespace std;
bool judge(int x){
	if(x<2)return 0;
    for(int i=2;i<=sqrt(x);++i){
        if(x%i==0)return 0;
    }
    return 1;
}
void transfer(int x,int d){
    vector<int> v;
    int y=0,s=1;
    if(judge(x)==0){printf("No\n");return;}
    while(x!=0){
        v.push_back(x%d);
        x/=d;
    }
    //cout<<endl;
    for(int i=v.size()-1;i>=0;--i){
        y+=v[i]*s;
        //cout<<v[v.size()-1-i];
        s*=d;
    }
    if(judge(y)==0)printf("No\n");
    else printf("Yes\n");
}
int main(){
    int x=0,d;
    while(1){
        scanf("%d",&x);if(x<0)break;
        scanf("%d",&d);transfer(x,d);
    }
    return 0;
}
