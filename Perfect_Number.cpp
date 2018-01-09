#include <iostream>
#include <math.h>
#include <set>
using namespace std;
class Solution105 {
public:
	bool checkPerfectNumber(int num) {
		if (num < 6)
			return false;
		int temp = num - 1;
		for (int i = 2; i <= sqrt(num); i++)
		{
			if (num%i==0)
			{
				temp = temp - i - num / i;
			}
		}
		if (temp == 0)
			return true;
		else
			return false;
	}
};
class Solution105_3 {
public:
	bool checkPerfectNumber(int num) {
		if (num < 6)
			return false;
		int temp = num - 1;
		for (int i = 2; i <= int(sqrt(num)); i++)
		{
			if (num%i == 0)
			{
				temp = temp - i - num / i;
			}
		}
		if (num == (int(sqrt(num)) * int(sqrt(num))))
			temp = temp + int(sqrt(num));
		if (temp == 0)
			return true;
		else
			return false;
	}
};
class Solution105_2 {
public:
	bool checkPerfectNumber(int num) {
		if (num < 6)
			return false;
		int temp = num - 1;
		int n = num;
		for (int i = 2; i < n ; i++)
		{
			if (num%i == 0)
			{
				temp = temp - i - num / i;
				n = num / i;
			}
		}
		if (temp == 0)
			return true;
		else
			return false;
	}
};
class Solution105_1 {
public:
	bool checkPerfectNumber(int num) {
		static set<int>s = { 6, 28, 496, 8128, 33550336 };
		return s.count(num);
	}
};
#if 0
void main()
{
	Solution105_3 s;
	cout << s.checkPerfectNumber(6) << endl;
	system("pause");
}
#else
#endif