#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
class Solution104 {//此法不通
public:
	bool sub(string s, string t)
	{
		string ss = s;
		string tt = t;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ' && s[i]!=tt[i])
			{
				char temp = tt[i];
				for (int j = i; j < tt.length(); j++)
				{
					if (tt[j] == temp)
					{
						tt[j] = s[i];
					}
				}
				for (int j = i + 1; j < s.length(); j++)
				{
					if (s[j] == s[i])
					{
						s[j] = ' ';
					}
				}
			}
		}
		if (tt == ss)
			return true;
		else
			return false;
	}
	bool isIsomorphic(string s, string t) {
		return sub(s, t) && sub(t, s);
	}
};
class Solution104_1 {	
public:
	bool sub(string s, string t)
	{
		map<char, char>m1;
		for (int i = 0; i < s.length(); i++)
		{
			if (m1[s[i]] == NULL)
				m1[s[i]] = t[i];
			else
				if (m1[s[i]] != t[i])
					return false;
		}
		return true;
	}
	bool isIsomorphic(string s, string t) {
		return sub(s, t) && sub(t, s);
	}
};
class Solution104_2 {
public:
	bool isIsomorphic(string s, string t) {
		vector<int>v1(256, -1);
		vector<int>v2(256, -1);
		for (int i = 0; i < s.length();i++)
		{
			if (v1[s[i]] != v2[t[i]])
				return false;
			v1[s[i]] = i;
			v2[t[i]] = i;
		}
		return true;
	}
};
#if 0
void main()
{
	Solution104_2 s;
	string t1 = "ab";
	string t2 = "aa";
	cout << s.isIsomorphic(t1, t2) << endl;
	system("pause");
}
#else
#endif