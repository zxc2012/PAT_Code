#include<bits/stdc++.h>
using namespace std;
vector<int> v,f;
vector<int> num2v(int n){
    vector<int> x;
    while(n!=0){
        x.push_back(n%10);
        n/=10;
    }
    return x;
}
int v2num(vector<int>& x){
    int s=0,m=1;
    for(int i=0;i<x.size();++i){
        s+=m*x[i];
        m*=10;
    }
    return s;
}
int main(){
    int n,sum=0,i;
    cin>>n;
    v=num2v(n);
    int num=v.size();f.resize(num);
    fill(f.begin(),f.end(),9);
    for(i=0;i<v.size();++i){
        vector<int> temp,temp1;
        if(v[i]==0){
            temp1.insert(temp.begin(),v.begin()+i+1,v.end());//left
            temp.insert(temp.begin(),f.begin(),f.begin()+i);//right
            temp1=num2v(v2num(temp1)-1);
            temp.insert(temp.end(),temp1.begin(),temp1.end());
            sum+=v2num(temp)+1;
        }
        else if(v[i]==1){
            temp.insert(temp.begin(),v.begin(),v.begin()+i);
            temp.insert(temp.end(),v.begin()+i+1,v.end());
            sum+=v2num(temp)+1;
        }
        else{
            temp.insert(temp.begin(),f.begin(),f.begin()+i);//right
            temp.insert(temp.end(),v.begin()+i+1,v.end());//left
            sum+=v2num(temp)+1;
        }
    }
    printf("%d",sum);
    return 0;
}
