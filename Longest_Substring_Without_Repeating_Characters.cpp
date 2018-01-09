#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution92 {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() == 0)
			return 0;
		if (s.length() == 1)
			return 1;				
		string sub = "";
		sub.append(1, s[0]);
		int in = 0;
		int count = 1;
		int temp = 1;
		int i = 1;
		while (i<s.length())
		{
			if (sub.find(s[i])==-1)
			{
				sub.append(1, s[i]);
				temp++;
			}
			else
			{
				in = sub.find(s[i]) + 1;
				sub.erase(0, in);
				sub.append(1, s[i]);
				temp = temp - in  + 1;
			}
			if (temp>count)
			{
				count = temp;
			}
			i++;
		}
		return count;
	}
};
class Solution92_1 {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int>c(256, -1);
		int count = 0;
		int first = -1;
		for (int i = 0; i < s.length();i++)
		{
			if (c[s[i]]>first)
				first = c[s[i]];
			c[s[i]] = i;
			count = count > (i - first) ? count : (i - first);
		}
		return count;
	}
};
#if 0
void main()
{
	Solution92_1 s;
	string ss = "pwwkew";
	cout << s.lengthOfLongestSubstring(ss) << endl;
	system("pause");
}
#else
#endif