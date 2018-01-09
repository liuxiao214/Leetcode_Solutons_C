#include <iostream>
#include <math.h>
using namespace std;
class Solution96 {
public:
	int arrangeCoins(int n) {
		if (n < 0)
			return 0;
		int count = 1;
		int i = 1;
		while (n>=count)
		{
			n = n - count;
			count++;
		}
		return count-1;
	}
};
class Solution96_1 {
public:
	int arrangeCoins(int n) {
		return floor(-0.5 + sqrt((double)2 * n + 0.25));
	}
};
#if 0
void main()
{
	Solution96_1 s;
	cout << s.arrangeCoins(8) << endl;
	cout << floor(-0.5 + sqrt((double)2 * 6200 + 0.25)) << endl;
	cout << float(-0.5 + sqrt((double)2 * 6200 + 0.25)) << endl;
	system("pause");
}
#else
#endif