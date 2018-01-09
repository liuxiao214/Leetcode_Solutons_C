#include <iostream>
#include <vector>
#include<string>
#include <math.h>
using namespace std;


class Solution135 {
public:
	long buildPalindrome(int n)
	{
		string s = to_string(n);
		reverse(s.begin(), s.end());
		return stol(to_string(n) + s);
	}
	int largestPalindrome(int n) {
		if (n == 1)
			return 9;
		int max = pow(10, n) - 1;
		int min = pow(10, n - 1);
		for (int i = max; i >= min;i--)
		{
			long mix = buildPalindrome(i);
			for (long j = max; j*j >= mix;j--)
			{
				if (mix%j == 0 && mix / j <= max)
					return mix % 1337;
			}
		}
		return -1;
	}
};
#if 0
void main()
{
	Solution135 s;
	cout << s.largestPalindrome(2) << endl;
	system("pause");
}
#else
#endif