#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Solution32 {
public:
	int titleToNumber(string s) {
		int sum = 0;
		for (int i = s.length()-1; i >= 0; i--)
		{
			sum = sum + (s[i] - 'A' + 1)*pow(26, s.length() - i - 1);
		}
		return sum;
	}
};
#if 0
void main()
{
	Solution32 s;
	cout << s.titleToNumber("ABB") << endl;
	system("pause");
}
#else
#endif
