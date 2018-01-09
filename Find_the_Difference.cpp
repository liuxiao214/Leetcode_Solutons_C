#include <iostream>
#include <string>
using namespace std;
class Solution16 {
public:
	char findTheDifference(string s, string t) {
		char a;
		for (int i = 0; i < t.length();i++)
		{
			int flag = 0;
			for (int j = 0; j < s.length();j++)
			{
				if (t[i]==s[j])
				{
					flag = 1;
					s.erase(j, 1);
					break;
				}
			}
			if (flag==0)
			{
				a = t[i];
			}
		}
		return a;
	}
};
#if 0
void main()
{
	Solution16 s;
	string t1 = "a";
	string t2 = "aa";
	cout << s.findTheDifference(t1, t2) << endl;
	system("pause");
}
#else
#endif