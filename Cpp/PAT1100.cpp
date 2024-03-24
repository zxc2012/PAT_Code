#include<bits/stdc++.h>
using namespace std;
string s1[13]= {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly","aug", "sep", "oct", "nov", "dec"};
string s2[12]= {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string,int>name2num;
map<int,string>num2name;
void transfer(int x) {
	if(x<=13)cout<<num2name[x]<<endl;
	else {
		int x1=x/13-1;
		int x2=x%13;
		if(x2==0)
		cout<<num2name[x1+13]<<endl;
		else 
		cout<<num2name[x1+13]<<" "<<num2name[x2]<<endl;
	}
}
int main() {
	int n,i,j;
	cin>>n;
	int c1,c2;
	string ss,ss1,ss2;
	for(i=0; i<13; ++i) {
		num2name[i]=s1[i];
		name2num[s1[i]]=i;
	}
	for(i=0; i<12; ++i) {
		num2name[i+13]=s2[i];
		name2num[s2[i]]=i+13;
	}
    getchar()
	for(i=0; i<n; ++i) {
		getline(cin,ss);
		if('0'<=ss[0]&&ss[0]<='9')transfer(stoi(ss));
		else {
            int len=ss.size();
            if(len>5){
                ss1=ss.substr(0,3);
				c1=name2num[ss1];
				ss2=ss.substr(4);
				c2=name2num[ss2];
				printf("%d\n",(c1-12)*13+c2);
            }
            else
            {
				c1=name2num[ss];
				if(c1>12)
				printf("%d\n",(c1-12)*13);
				else
				printf("%d\n",c1);
			}
		}
	}
	return 0;
}