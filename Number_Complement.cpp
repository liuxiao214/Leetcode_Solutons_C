#include <iostream>
#include <math.h>
using namespace std;
class Solution2 {
public:
	int findComplement(int num) {
		int a[100];
		int i = 0;
		while (num > 0)
		{
			a[i++] = num % 2;
			num = num / 2;
		}
		int newnum = 0;
		for (int j = 0; j < i; j++)
		{
			newnum = newnum + (1-a[j]) * pow(2, j);
		}
		return newnum;
	}
};
#if 0
void main()
{
	Solution2 s2;
	cout << s2.findComplement(5) << endl;
	system("pause");
}
#else
#endif