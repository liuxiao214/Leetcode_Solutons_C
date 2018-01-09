#include <iostream>
#include <string>
using namespace std;

class Solution100 {
public:
	bool isPalindrome(int x) {
		string s = to_string(x);
		int i = 0;
		int j = s.length() - 1;
		while (i<=j)
		{
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
};
class Solution100_1 {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x!=0 && x % 10 == 0))
			return false;
		int xt = x;
		int y = 0;
		while (x>0)
		{
			y = y * 10 + x % 10;
			x = x / 10;
		}
		return xt == y;
	}
};
class Solution100_2 {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0))
			return false;
		int y = 0;
		while (x > y)
		{
			y = y * 10 + x % 10;
			x = x / 10;
		}
		return x == y || x==(y/10);
	}
};
#if 0
void main()
{
	Solution100_2 s;
	cout << s.isPalindrome(101) << endl;
	system("pause");
}
#else
#endif