#include <iostream>
#include <math.h>
#include <set>
using namespace std;
class Solution63 {
public:
	bool isHappy(int n) {
		set<int>a;
		int flag = 1;
		while (n!=1)
		{
			int sum = 0;
			while (n > 0)
			{
				sum = sum + pow(n % 10, 2);
				n = n / 10;
			}
			if (a.count(sum))
			{
				flag = 0;
				break;
			}
			else
				a.insert(sum);
			n = sum;
		}
		if (flag == 1)
			return true;
		else
			return false;
	}
};
class Solution63_1 {
public:
	bool isHappy(int n) {
		/*这是因为，在前1，2，3，4，5，6，中，
		1是快乐数，2,3,4,5,6都会回到2的状态，也就是非快乐数，
		所以将循环一直持续到计算出sum为小于等于6的数，然后判断此时的数是否等于1就可以了。
		*/
		while (n>6)
		{
			int sum = 0;
			while (n>0)
			{
				sum = sum + pow(n % 10, 2);
				n = n / 10;
			}
			n = sum;
		}
		return n == 1;
	}
};
#if 0
void main()
{
	Solution63_1 s;
	cout << s.isHappy(8) << endl;
	system("pause");
}
#else
#endif