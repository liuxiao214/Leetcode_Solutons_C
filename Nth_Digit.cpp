#include <iostream>
#include <string>
using namespace std;

class Solution119 {
public:
	int findNthDigit(int n) {
		long digit = 1;//ȷ������һλ
		long base = 9;//ÿλ�����ĸ���
		long ith = 1;//��ʼֵ
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