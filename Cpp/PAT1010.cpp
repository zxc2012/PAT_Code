#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int transfer(int a,int x){
    string s=to_string(a);
    int sum=0,y=1;
    for(int i=s.size()-1;i>=0;--i){
        if(s[i]<='9')s[i]-='0';
        else s[i]-='a'+10;
        sum+=s[i]*y;
        y*=x;
    }
	//cout<<sum<<endl;
    return sum;
}
int main(){
    int n1,n2,tag,radix;
    cin>>n1>>n2>>tag>>radix;
    if(tag==1){
        n1=transfer(n1,radix);
        for(int i=1;i<inf;++i){
            if(transfer(n2,i)>=n1){
                if(transfer(n2,i)>n1)printf("Impossible");
                else printf("%d",i);
                break;
            }
        }
    }
    else {
        n2=transfer(n2,radix);
        for(int i=1;i<inf;++i){
            if(transfer(n1,i)>=n2){
                if(transfer(n1,i)>n2)printf("Impossible");
                else printf("%d",i);
                break;
            }
        }
    }
    return 0;
}
