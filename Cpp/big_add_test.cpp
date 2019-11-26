#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
class largeNum
{

public:
	string num;
	friend largeNum operator+ (largeNum& num1, largeNum& num2);
	largeNum operator= (largeNum& num1);
};
largeNum largeNum::operator= (largeNum& num1)
{
	this->num = num1.num;
	return num1;
}
largeNum operator+ (largeNum& num1, largeNum& num2)
{
	largeNum s;
	int carry=0,m=0,x1,x2;
	reverse(num1.num.begin(),num1.num.end());
	reverse(num2.num.begin(),num2.num.end());
	for (int i = 0; i < num1.num.size() || i < num2.num.size(); i++)
	{
		x1=i < num1.num.size()?num1.num[i]-'0':0;
		x2=i < num2.num.size()?num2.num[i]-'0':0;
		int temp=x1+x2+carry;
		s.num.push_back(temp%10+'0');carry=temp/10;
		//printf("%c ",temp%10+'0');
	}
	reverse(s.num.begin(),s.num.end());
	return s;
}
int main()
{
	largeNum we, la;
	getline(cin, we.num);
	getline(cin, la.num);

	largeNum wela = we + la;
	std::cout << wela.num << std::endl;
	return 0;
}
