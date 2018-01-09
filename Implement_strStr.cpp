#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution124 {
public:
	int strStr(string haystack, string needle) {
		if (needle.length() == 0)
			return 0;
		if (haystack.length() < needle.length())
			return -1;
		for (int k = 0; k <= haystack.length() - needle.length();k++)
		{
			int i = k;
			int j = 0;
			int flag = 1;
			while (j<needle.length())
			{
				if (haystack[i] != needle[j])
				{
					flag = 0;
					break;
				}			
				i++;
				j++;
			}
			if (flag == 1)
				return i - j;
		}
		return -1;
	}
};
class Solution124_1 {
public:
	int strStr(string haystack, string needle) {
		if (needle.length() == 0)
			return 0;
		int n = haystack.length();
		int m = needle.length();
		for (int k = 0; k <= n-m; k++)
		{
			int j = 0;
			while (j < m)
			{
				if (haystack[k+j] != needle[j])
					break;
				j++;
			}
			if (j == m)
				return k;
		}
		return -1;
	}
};
class Solution124_2 {
public:
	vector<int> findnext(string s)
	{
		vector<int>next(1,-1);
		int k;
		for (int i = 1; i < s.length();i++)
		{
			k = next[i - 1];
			while (k>-1)
			{
				if (s[k] == s[i - 1])
				{
					next.push_back(k + 1);
					break;
				}
				else
					k = next[k];
			}
			if (k==-1)
				next.push_back(0);	
		}
		return next;
	}
	int strStr(string haystack, string needle) {
		if (needle.length() == 0)
			return 0;
		if (haystack.length() < needle.length())
			return -1;
		vector<int>next = findnext(needle);
		int i = 0;
		int j = 0;
		int n = haystack.length();
		int m = needle.length();
		while (i<n && j<m)
		{
			if (j == -1 || haystack[i]==needle[j])
			{
				i++;
				j++;
			}
			else if (j != -1 && haystack[i] != needle[j])
			{
				j = next[j];
			}
		}
		if (j == needle.length())
			return i - j;
		else
			return -1;
	}
};

#if 0
void main()
{
	Solution124_2 s;
	string s1 = "BBCFABCDABFABCDABDDABDE";
	string s2 = "ABCDABD";
	vector<int>next = s.findnext(s2);
	cout << "s=" << s1 << endl;
	cout << "p=" << s2 << endl<<endl;
	cout << "first index is : "<<s.strStr(s1, s2) << endl<<endl;
	system("pause");
}
#else
#endif