#include <iostream>
#include <stdint.h>
using namespace std;
class Solution73 {
public:
	int hammingWeight(uint32_t n) {
		int sum = 0;
		while (n>0)
		{
			if (n % 2 == 1)
				sum++;
			n = n / 2;
		}
		return sum;
	}
};
class Solution73_1 {
public:
	int hammingWeight(uint32_t n) {
		int sum = 0;
		while (n > 0)
		{
			n = n&(n - 1);
			sum++;
		}
		return sum;
	}
};
#if 0
void main()
{
	Solution73_1 s;
	cout << s.hammingWeight(11) << endl;
	system("pause");
}
#else
#endif