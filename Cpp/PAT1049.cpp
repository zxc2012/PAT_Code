#include<bits/stdc++.h>
using namespace std;
vector<int> v,g;
int sum=1,mo;
void transfer(int n){
    while(n!=0){
        v.push_back(n%10);
        if(n>=10)g.push_back(10);
        else {mo=n%10+1;g.push_back(mo);}
        sum*=g.back();
        n/=10;
    }
}
int main(){
    int n,temp=0,i;
    cin>>n;
    transfer(n);
    for(i=0;i<v.size();++i){
        if(v[i]<1)temp+=sum*(mo-1)/(g[i]*mo);
        else temp+=sum/g[i];
        
    }
    printf("%d",temp);
    return 0;
}
