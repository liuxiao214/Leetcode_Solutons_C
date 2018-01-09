#include <iostream>
#include <vector>
using namespace std;

class Solution97 {
public:
	int trailingZeroes(int n) {
		return n < 5 ? 0 : n / 5 + trailingZeroes(n / 5);
	}
};
class Solution97_1 {
public:
	int trailingZeroes(int n) {
		int c = 0;
		while (n>0)
		{
			n = n / 5;
			c = c + n;
		}
		return c;
	}
};
#if 0
void main()
{
	Solution97_1 s;
	cout << s.trailingZeroes(25) << endl;
	int n = 15;
	int m = 1;
	while (n>0)
	{
		m = m*n;
		n--;
	}
	cout << m << endl;
	system("pause");
}
#else
#endif