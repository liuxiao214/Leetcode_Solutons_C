#include <iostream>
#include <string>
using namespace std;

class Solution94 {//³¬Ê±
public:
	string longestPalindrome(string s) {	
		if (s.length() == 0)
			return "";
		if (s.length() == 1)
			return s;
		int first = 0;
		int count = 1;
		for (int k = 0; k < s.length(); k++)
		{		
			int c_temp = 0;
			for (int p = s.length() - 1; p > k; p--)
			{	
				int i = k;
				if (s[i] != s[p])
					continue;
				int j = p;
				c_temp = 2;
				i++;
				j--;
				while (i < j)
				{
					if (s[i] != s[j])
					{
						c_temp = 0;
						break;
					}
					else
					{
						i++;
						j--;
						c_temp += 2;
					}
				}
				if (i == j)
				{
					c_temp += 1;
				}	
				if (c_temp > count)
				{
					count = c_temp;
					first = k;
				}
			}	
		}
		return s.substr(first,count);
	}
};
class Solution94_1 {
public:
	string ishuiwen(string s,int x,int y)
	{
		int count;
		if (x == y)
		{
			count = 1;
			x--;
			y++;
		}				
		else
			count = 0;	
		while (x>=0 && y<s.length() && s[x]==s[y] )
		{
			x--;
			y++;
			count += 2;
		}
		return s.substr(x + 1, count);
	}
	string longestPalindrome(string s) {
		if (s.length() == 0)
			return "";
		if (s.length() == 1)
			return s;
		string sub = s.substr(0, 1);
		for (int k = 0; k < s.length()-1;k++)
		{
			string s1 = ishuiwen(s,k,k);
			if (s1.length()>sub.length())
				sub = s1;
			string s2 = ishuiwen(s, k, k+1);
			if (s2.length() > sub.length())
				sub = s2;
		}
		return sub;
	}
};
#if 0
void main()
{
	Solution94_1 s;
	string ss = "bb";
	string sub = s.longestPalindrome(ss);
	cout << s.longestPalindrome(ss) << endl;
	system("pause");
}
#else
#endif