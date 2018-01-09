#include <iostream>
#include <string>
using namespace std;
class Solution102 {
public:
	string say(string s)
	{
		int l = s.length()-1;
		string t = "";
		int i = 0;
		int count = 1;
		int flag = 0;
		while (i<l)
		{
			if (s[i]==s[i+1])
			{
				count++;
				flag = 0;
			}
			else
			{
				string temp = to_string(count);
				t = t + temp + s[i];
				count = 1;
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
		{
			string temp = to_string(count);
			t = t + temp + s[i];
		}
		else
		{
			t = t + "1" + s[i];
		}
		return t;
	}
	string countAndSay(int n) {
		if (n < 1)
			return "";
		string f="1";
		while (n>1)
		{
			f = say(f);
			n--;
		}
		return f;
	}
};
#if 0
void main()
{
	Solution102 s;
	string sss = s.countAndSay(4);
	cout<<sss<< endl;
	system("pause");
}
#else
#endif