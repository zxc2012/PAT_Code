#include <bits/stdc++.h>
using namespace std;
int main() {
	double a, b;
	unsigned char n,st1,st2;
	int p1, p2;
	scanf("%d %lf %lf",&n,&a,&b);
	string s1=to_string(a);
	if(s1.c_str()[0]!='0') {
		if (s1.find('.') == string::npos)
			p1 = s1.size();
		else {
			p1 = s1.find('.');
			s1.erase(p1,1);
		}

		if (n < s1.size())
			s1 = s1.substr(0, n);
		else {
			s1.insert(s1.end(), n - s1.size(), '0');
			s1 = s1.substr(0, n);
		}

	} else {
		if(s1.find_first_not_of("0.")==string::npos)
			st1=2;
		else
			st1 = s1.find_first_not_of("0.");
		p1 = 2-st1;
		if (n < s1.size()-st1)
			s1 = s1.substr(st1, n);
		else {
			s1.insert(s1.end(), n - s1.size()+st1, '0');
			s1 = s1.substr(st1, n);
		}
	}
	string s2 = to_string(b);
	if (s2.c_str()[0] != '0') {
		if (s2.find('.') == string::npos)
			p2 = s2.size();
		else {
			p2 = s2.find('.');
			s2.erase(p2,1);
		}
		if (n < s2.size())
			s2 = s2.substr(0, n);
		else {
			s2.insert(s2.end(), n - s2.size()+st2, '0');
			s2 = s2.substr(0, n);
		}
	} else {
		if(s2.find_first_not_of("0.")==string::npos)
			st2=2;
		else
			st2 = s2.find_first_not_of("0.");
		p2 = 2-st2 ;
		if (n < s2.size() - st2)
			s2 = s2.substr(st2, n);
		else {
			s2.insert(s2.end(), n - s2.size() + st2, '0');
			s2 = s2.substr(st2, n);
		}
	}
	if (s1 != s2) {
		printf("NO ");
		printf("0.%s*10^%d ", s1.c_str(), p1);
		printf("0.%s*10^%d", s2.c_str(), p2);
	}

	else {
		printf("YES ");
		printf("0.%s*10^%d", s1.c_str(), p1);
	}


	return 0;
}
