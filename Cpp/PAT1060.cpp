#include <bits/stdc++.h>
using namespace std;
char a[101],b[101];
vector<char> v1,v2;
int main() {
	int n,i,p1=-1,n1=-1,p2=-1,n2=-1,l1=-1,l2=-1,f1=0,f2=0,ff1=0,ff2=0;
	scanf("%d %s %s",&n,a,b);
	for(i=0;i<100;++i){
		if(a[i]=='.')p1=i;
		if(b[i]=='.')p2=i;
		if(a[i]<='9'&&a[i]>'0'&&f1==0){f1=1;n1=i;}
		if(b[i]<='9'&&b[i]>'0'&&f2==0){f2=1;n2=i;}
		if(a[i]<46&&ff1==0)l1=i,ff1=1;
		if(b[i]<46&&ff2==0)l2=i,ff2=1;
		if(a[i]<46&&b[i]<46)break;		
	}
	int temp[n];fill(temp,temp+n,'0');
	if(n1==-1){v1.insert(v1.begin(),temp,temp+n);p1=n1;}
	else{
		if(l1-n1-(p1>n1?1:0)<n){//zero
			if(p1>n1){
				v1.insert(v1.begin(),a+n1,a+p1);
				v1.insert(v1.end(),a+p1+1,a+l1);
			}else v1.insert(v1.begin(),a+n1,a+l1);		
		}
		else{
 			if(p1>n1&&p1<n1+n){//no zero
				v1.insert(v1.begin(),a+n1,a+p1);
				v1.insert(v1.end(),a+p1+1,a+n1+n+1);		
			}
			else v1.insert(v1.begin(),a+n1,a+n1+n);
		}
		if(p1==-1)p1=l1;
	}
	if(n2==-1){v2.insert(v2.begin(),temp,temp+n);p2=n2;}
	else{
		if(l2-n2-(p2>n2?1:0)<n){
			if(p2>n2){
				v2.insert(v2.begin(),b+n2,b+p2);
				v2.insert(v2.end(),b+p2+1,b+l2);
			}else v2.insert(v2.begin(),b+n2,b+l2);
		}
		else{
			if(p2>n2&&p2<n2+n){
				v2.insert(v2.begin(),b+n2,b+p2);
				v2.insert(v2.end(),b+p2+1,b+n2+n+1);
			}
			else v2.insert(v2.begin(),b+n2,b+n2+n);
		} 
		if(p2==-1)p2=l2;
	}
	if(v1==v2&&p1-n1==p2-n2){
		printf("YES 0.");
		for(i=0;i<v1.size();++i)printf("%c",v1[i]);
		printf("*10^%d",p1-n1+(p1<n1&&p1>-1?1:0));
	}
	else{
		printf("NO 0.");
		for(i=0;i<v1.size();++i)printf("%c",v1[i]);
		printf("*10^%d 0.",p1-n1+(p1<n1&&p1>-1?1:0));
		for(i=0;i<v2.size();++i)printf("%c",v2[i]);
		printf("*10^%d",p2-n2+(p2<n2&&p2>-1?1:0));
	} 
	return 0;
}
