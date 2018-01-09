#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution106_0 {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int>a;
		if (s.length() < p.length())
			return a;
		vector<int>b(27, 0);
		for (int i = 0; i < p.length(); i++)
			b[p[i] - 'a']++;
		for (int i = 0; i < s.length(); i++)
		{
			vector<int>temp(27, 0);
			if (i + p.length() > s.length())
				break;
			for (int j = i; j < i + p.length(); j++)
				temp[s[j] - 'a']++;
			int flag = 1;
			for (int k = 0; k < b.size(); k++)
			{
				if (b[k] != temp[k])
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				a.push_back(i);
		}
		return a;
	}
};
class Solution106 {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int>a;
		if (s.length() < p.length())
			return a;
		vector<int>b(27,0);
		for (int i = 0; i < p.length(); i++)
			b[p[i]-'a']++;
		for (int i = 0; i < s.length();i++)
		{
			vector<int>temp(27, 0);
			if (i + p.length() > s.length())
				break;
			for (int j = i; j < i + p.length(); j++)
				temp[s[j]-'a']++;
			if (b == temp)
				a.push_back(i);
		}
		return a;
	}
};
class Solution106_1 {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int>a;
		if (s.length() < p.length())
			return a;
		vector<int>sc(27, 0);
		vector<int>pc(27, 0);
		for (int j = 0; j < p.length();j++)
		{
			pc[p[j] - 'a']++;
			sc[s[j] - 'a']++;
		}
		if (pc == sc)
			a.push_back(0);
		for (int i = 1; i < s.length();i++)
		{
			if (i+p.length()>s.length())
				break;
			sc[s[i-1] - 'a']--;
			sc[s[i+p.length()-1] - 'a']++;
			if (pc == sc)
				a.push_back(i);
		}
		return a;
	}
};
#if 0
void main()
{
	Solution106_1 s;
	string s1 = "abab";
	string s2 = "ab";
	vector<int>a = s.findAnagrams(s1, s2);
	for (int i = 0; i < a.size();i++)
	{
		cout << a[i] << endl;
	}
	system("pause");
}
#else
#endif