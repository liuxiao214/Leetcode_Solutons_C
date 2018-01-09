#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution3 {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> newwords;
		vector<char> a = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
			'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P' };
		vector<char> b = {'a','s','d','f','g','h','j','k','l',
		'A','S','D','F','G','H','J','K','L'};
		vector<char> c = {'z','x','c','v','b','n','m',
		'Z','X','C','V','B','N','M'};
		for (int i = 0; i < words.size(); i++)
		{		
			char temp = words[i][0];
			int flag = 0;
			int flag1 = 0;
			int flag2 = 0;
			vector<char>::iterator result1 = find(a.begin(), a.end(), temp); //查找3
			vector<char>::iterator result2 = find(b.begin(), b.end(), temp); //查找3
			vector<char>::iterator result3 = find(c.begin(), c.end(), temp); //查找3
			if (result1 != a.end() && result2 == b.end() && result3 == c.end()) //没找到
				flag = 1;
			else if (result1 == a.end() && result2 != b.end() && result3 == c.end())//找到
				flag = 2;
			else
				flag = 3;
			
			for (int j = 1; j < words[i].length(); j++)
			{
				vector<char>::iterator result11 = find(a.begin(), a.end(), words[i][j]); //查找3
				vector<char>::iterator result22 = find(b.begin(), b.end(), words[i][j]); //查找3
				vector<char>::iterator result33 = find(c.begin(), c.end(), words[i][j]); //查找3
				if (result11 != a.end() && result22 == b.end() && result33 == c.end()) //没找到
					flag1 = 1;
				else if (result11 == a.end() && result22 != b.end() && result33 == c.end())//找到
					flag1 = 2;
				else
					flag1 = 3;
				if (flag == flag1)
				{
					flag2 = 1;
					continue;
				}			
				else
				{
					flag2 = 0;
					break;
				}		
			}
			if (flag2 == 1 || words[i].length() == 1)
			{
				newwords.push_back(words[i]);
			}
		}
		return newwords;
	}
};
#if 0
void main()
{
	Solution3 s;
	vector<string>arr = { "Hello", "Alaska", "Dad", "Peace" ,"a","b"};
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
	vector<string>newa = s.findWords(arr);
	for (int i = 0; i < newa.size();i++)
	{
		cout << newa[i] << endl;
	}
	system("pause");
}
#else
#endif