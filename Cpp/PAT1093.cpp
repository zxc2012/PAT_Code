#include<bits/stdc++.h>
using namespace std;
vector<int> p,a,t;
int main() {
	int i=0,j;
	long long sum=0;
	char c;
	while(c=getchar()) {
		if(c=='\n')break;
		if(c=='P')p.push_back(i);
		else if(c=='A')a.push_back(i);
		else if(c=='T')t.push_back(i);
		++i;
	}
	auto temp1=p.begin(),temp2=t.begin();
	int x1=0,x2=0;
	for(i=0; i<a.size(); ++i) {
		auto x=temp1;
		temp1=lower_bound(x,p.end(),a[i]);
		temp2=upper_bound(temp2,t.end(),a[i]);
		x1+=(int)(temp1-x);
		x2=(int)(t.end()-temp2);
		sum+=x1*x2;
	}
	printf("%d",sum%1000000007);
	return 0;
}
