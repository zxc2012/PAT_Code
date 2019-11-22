#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
long long transfer(vector<int>& v,long long& x) {
	long long sum=0;
    long long y=1;
	for(int i=v.size()-1; i>=0; --i) {
		sum+=v[i]*y;
		y*=x;
	}
	//cout<<x<<" "<<sum<<endl;
	return sum;
}
void binary(vector<int>& v,long long& cp){
    long long l,h,mid,temp;
    l=*max_element(v.begin(),v.end())+1;
    h=max(l,cp);
    while(l<=h){
        mid=(l+h)/2;temp=transfer(v,mid);
        if(temp<0||temp>cp)h=mid-1;
        else if(temp<cp)l=mid+1;
        else {printf("%lld",mid);return;}
    }printf("Impossible");    
}
int main() {
	int tag;
	string n1,n2;
	long long num1,num2,radix,maxi=0;
	cin>>n1>>n2>>tag>>radix;
    for(int i=0; i<n2.size();++i){
        if(n2[i]<='9')v2.push_back(n2[i]-'0');
        else v2.push_back(n2[i]-'a'+10);
    }
    for(int i=0; i<n1.size();++i){
        if(n1[i]<='9')v1.push_back(n1[i]-'0');
        else v1.push_back(n1[i]-'a'+10);
    }
	if(tag==1){
		num1=transfer(v1,radix);
        binary(v2,num1);
	}
    else if(tag==2){
		num2=transfer(v2,radix);
        binary(v1,num2);
	}
    return 0;
}
