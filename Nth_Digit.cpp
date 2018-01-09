#include <iostream>
#include <string>
using namespace std;

class Solution119 {
public:
	int findNthDigit(int n) {
		long digit = 1;//确定是哪一位
		long base = 9;//每位的数的个数
		long ith = 1;//起始值
		while (n>base*digit)
		{
			n = n - base*digit;
			digit++;
			ith = ith + base;
			base = base * 10;
		}
		return to_string(ith + (n - 1) / digit)[(n - 1) % digit] - '0';
	}
};

#if 0
void main()
{
	Solution119 s;
	cout << s.findNthDigit(23456) << endl;
	system("pause");
}
#else
#endif