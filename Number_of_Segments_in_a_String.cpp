#include <iostream>
#include <string>
using namespace std;
class Solution89 {
public:
	int countSegments(string s) {
		if (s.length() == 0)
			return 0;
		int count = 0;
		for (int i = 0; i < s.length() - 1; i++)
		{
			if (s[i] == ' ' && s[i + 1] != ' ')
				count++;
		}
		if (s[0] != ' ')
			count++;
		return count;
	}
};
class Solution89_1 {
public:
	int countSegments(string s) {
		s = s + ' ';
		int count=0;
		for (int i = 1; i < s.length(); i++)
		{
			if (s[i] == ' ' && s[i - 1] != ' ')
				count++;
		}
		return count;
	}
};
#if 0
void main()
{
	Solution89_1 s;
	string s1 = "  qwe e w a";
	string s2 = "  qwe e w";
	string s3 = "qwe e w  ";
	string s4 = "qwe e w";
	cout << s.countSegments(s1) << endl;
	cout << s.countSegments(s2) << endl;
	cout << s.countSegments(s3) << endl;
	cout << s.countSegments(s4) << endl;
	system("pause");
}
#else
#endif