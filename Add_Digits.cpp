#include <iostream>
using namespace std;
class Solution20 {
public:
	int addDigits(int num) {
		if (num == 0)
			return 0;
		else if (num % 9 == 0)
			return 9;
		else
			return num % 9;
	}
	int addDigits1(int num) {
		while ((num / 10)>0)
		{
			int temp = num / 10;
			num = num % 10 + temp;
		}
		return num;
	}
};
#if 0
void main()
{
	Solution20 s;
	cout << s.addDigits(38) << endl;
	cout << s.addDigits(36) << endl;
	system("pause");
}
#else
#endif