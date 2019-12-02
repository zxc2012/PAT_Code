#include<bits/stdc++.h>
using namespace std;
int main(){
    int d,n,i,j;
    scanf("%d %d",&d,&n);
    vector<int> v(1,d),temp;
    for(i=0;i<n-1;++i){
        temp.clear();
        for(j=0;j<v.size();++j){
            int x=1;
            while(j+1<v.size()&&v[j]==v[j+1]){x++;++j;}
            temp.push_back(v[j]);
            temp.push_back(x);
        }
        v=temp;
    }
    for(i=0;i<v.size();++i)printf("%d",v[i]);
    return 0; 
}