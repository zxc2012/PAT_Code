#include<bits/stdc++.h>
using namespace std;
map<int,int> sq;
struct node {
	float grade;
	int index;
};
vector<node> c,ma,en,av;
bool cmp(node a,node b) {
	return a.grade>b.grade;
}
int main() {
	int n,m;
	cin>>n>>m;
	int min=2000;
	int i,j;
	int c1,c2,c3,c4;
	int C,MA,EN,AV;
	for(i=0; i<n; ++i) {
		cin>>c1>>c2>>c3>>c4;
		sq[c1]=i+1;
		c.push_back({c2*1.0,i});
		ma.push_back({c3*1.0,i});
		en.push_back({c4*1.0,i});
		av.push_back({(c2+c3+c4)/3.0,i});
	}
	sort(c.begin(),c.end(),cmp);
	sort(ma.begin(),ma.end(),cmp);
	sort(en.begin(),en.end(),cmp);
	sort(av.begin(),av.end(),cmp);
	int a[4]= {0,0,0,0};
	char b[5]= {'A','C','M','E'};
	for(i=0; i<m; ++i) {
		cin>>c1;
		min=2000;
		fill(a,a+4,0);
		int flag=0;
		for(j=0; j<n; ++j) {
			if(sq[c1]!=0&&c[j].index==sq[c1]-1) {
				flag=1;
				break;
			}
		}
		if(flag==0) {
			printf("N/A\n");
			break;
		}
		for(j=0; j<n; ++j) {
			if(ma[j].index==sq[c1]-1) {
				MA=j;
				if(j<min)  min=j;
				break;
			}
		}
		for(j=0; j<n; ++j) {
			if(en[j].index==sq[c1]-1) {
				EN=j;
				if(j<min)  min=j;
				break;
			}
		}
		for(j=0; j<n; ++j) {
			if(av[j].index==sq[c1]-1) {
				AV=j;
				if(j<min)  min=j;
				break;
			}
		}
		for(j=0; j<n; ++j) {
			if(c[j].index==sq[c1]-1) {
				C=j;
				if(j<min)  min=j;
				break;
			}
		}
		if(AV==min) a[0]=1;
		if(C==min) a[1]=1;
		if(MA==min) a[2]=1;
		if(EN==min) a[3]=1;
		for(j=0; j<4; ++j) {
			if(a[j]==1) {
				printf("%d %c\n",min+1,b[j]);
				break;
			}
		}

	}
	return 0;
}
