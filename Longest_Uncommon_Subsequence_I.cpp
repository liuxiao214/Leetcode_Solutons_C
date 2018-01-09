#include <iostream>
#include <string>
using namespace std;
class Solution19 {
public:
	int findLUSlength(string a, string b) {
		if (a==b)
		{
			return -1;
		}
		int a_len = a.length();
		int b_len = b.length();
		if (a_len > b_len)
			return a_len;
		else
			return b_len;
	}
};
#if 0
void main()
{
	Solution19 s;
	cout << s.findLUSlength("sefsg", "sgsdgsd") << endl;
	system("pause");
}
#else
#endif