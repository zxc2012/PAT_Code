#include<bits/stdc++.h>
using namespace std;
struct p {
	int c;
	int v;
	int t;
};
vector<p>sage,noble,fool,ord;
bool cmp(p a,p b) {
	if(a.v+a.t>b.v+b.t)
		return 1;
	else if(a.v+a.t==b.v+b.t) {
		if(a.v>b.v)
			return 1;
		else if(a.v==b.v) {
			if(a.c<b.c)
				return 1;
			else return 0;
		} else return 0;
	} else return 0;
}
int main() {
	int n,l,h,i,number=0;
	cin>>n>>l>>h;
	int c1,c2,c3;
	for(i=0; i<n; ++i) {
		cin>>c1>>c2>>c3;
		p s= {c1,c2,c3};
		if(c2>=l&&c3>=l) {
			number++;
			if(c2>=h&&c3>=h)sage.push_back(s);
			else if(c2>=h)noble.push_back(s);
			else if(c2>=c3)fool.push_back(s);
			else ord.push_back(s);
		}
	}
	sort(sage.begin(),sage.end(),cmp);
	sort(noble.begin(),noble.end(),cmp);
	sort(fool.begin(),fool.end(),cmp);
	sort(ord.begin(),ord.end(),cmp);
	printf("%d\n",number);
	for(i=0; i<sage.size(); ++i) {
		printf("%d %d %d\n",sage[i].c,sage[i].v,sage[i].t);
	}
	for(i=0; i<noble.size(); ++i) {
		printf("%d %d %d\n",noble[i].c,noble[i].v,noble[i].t);
	}
	for(i=0; i<fool.size(); ++i) {
		printf("%d %d %d\n",fool[i].c,fool[i].v,fool[i].t);
	}
	for(i=0; i<ord.size(); ++i) {
		printf("%d %d %d\n",ord[i].c,ord[i].v,ord[i].t);
	}
	return 0;
}
