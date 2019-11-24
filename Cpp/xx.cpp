#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
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
	for (int i = 0; i < num1.num.size() || i < num2.num.size(); i++)
	{
		if (i == 0)
		{
			s.num[i] = '0';
			continue;
		}
		s.num[i] = num1.num[i - 1] + num2.num[i - 1] - '0';
		if (s.num[i] > '9')
		{
			s.num[i] -= 10;
			s.num[i - 1]++;
		}
	}
	cout<<s.num;
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
