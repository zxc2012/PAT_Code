#include<bits/stdc++.h>
using namespace std;
int charge[24];
int day_charge=0;
struct Node {
	string ID;
	int t[4];
	int status;
};
vector<Node> v;
map<string,int> m;
bool cmp(Node a,Node b) {
	if(a.ID!=b.ID)return a.ID<b.ID;
	else {
		int t1=a.t[1]*24*60+a.t[2]*60+a.t[3];
		int t2=b.t[1]*24*60+b.t[2]*60+b.t[3];
		return t1<t2;
	}
}
float cal(int* a) {
	float x;
    x=a[1]*day_charge+charge[a[2]]*a[3];
    for(int i=0; i<a[2]; ++i)
        x+=charge[i]*60;
	return x/100.0;
}
int cal1(int* a,int* b) {
	int t1=a[1]*24*60+a[2]*60+a[3];
	int t2=b[1]*24*60+b[2]*60+b[3];
	return (t2-t1);
}
int main() {
	int n,i,mon,j;
	string s,ss;
	for(i=0; i<24; ++i) {
		cin>>charge[i];
		day_charge+=charge[i]*60;
	}
	cin>>n;
	int c1,c2,c3;
	for(i=0; i<n; ++i) {
		cin>>s;
		scanf(" %d:%d:%d:%d ",&mon,&c1,&c2,&c3);
		getline(cin,ss);
		if(ss[1]=='n') { //s
			v.push_back({s,{mon,c1,c2,c3},0});
		} else {
			v.push_back({s,{mon,c1,c2,c3},1});
		}
	}
	sort(v.begin(),v.end(),cmp);
	float x;
	float sum;
	for(i=0; i<v.size(); ++i) {
		if(v[i].ID==v[i+1].ID&&v[i].status==0&&v[i+1].status==1) {
			if(m[v[i].ID]==0) {
				sum=0;
				m[v[i].ID]=i+1;
				cout<<v[i].ID<<" ";
				printf("%02d\n",v[i].t[0]);
			}
			x=cal(v[i+1].t)-cal(v[i].t);
			int y=cal1(v[i].t,v[i+1].t);
			sum+=x;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",v[i].t[1],v[i].t[2],v[i].t[3],v[i+1].t[1],v[i+1].t[2],v[i+1].t[3],y,x);
		}
		if(m[v[i].ID]!=0&&(i==v.size()-1||v[i].ID!=v[i+1].ID)) {
			printf("Total amount: $%.2f\n",sum);
		}
	}
	return 0;
}