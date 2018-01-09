#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution131 {
public:
	string convertToTitle(int n) {
		string s = "";
		if (n < 1)
			return s;
		int i = 1;
		while (n > 0)
		{
			int d = n % 26;
			n = n / 26;
			if (d == 0)
			{
				d = 26;
				n--;
			}
			char c = d + 64;
			s = c + s;
		}
		return s;
	}
};
class Solution131_1{
public:
	string convertToTitle(int n) {
		string s = "";
		if (n < 1)
			return s;
		int i = 1;
		while (n > 0)
		{
			n = n - 1;
			int d = n % 26;
			n = n / 26;
			char c = d + 65;
			s = c + s;
		}
		return s;
	}
};
#if 0
void main()
{
	Solution131_1 s;
	string ss = s.convertToTitle(52);
	cout << ss << endl;
	system("pause");
}
#else
#endif