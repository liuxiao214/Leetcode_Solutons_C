#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution117 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string pre = "";
		if (strs.size() == 0)
			return pre;
		for (int i = 0; i < strs[0].length();i++)
		{
			if (i >= strs[0].length())
				return pre;
			char temp = strs[0][i];
			for (int j = 0; j < strs.size();j++)
			{
				if (i >= strs[j].length() || strs[j][i] != temp)
					return pre;
			}
			pre.append(1,temp);
		}
		return pre;
	}
};

#if 0
void main()
{
	Solution117 s;
	vector<string>strs = {"abcdefg","abcdefghijk","abcdfghijk","abcef"};
	string p = s.longestCommonPrefix(strs);
	cout << p << endl;
	system("pause");
}
#else
#endif