#include <iostream>
#include <string>
using namespace std;
class Solution12 {
public:
	bool detectCapitalUse(string word) {
		int flag = 1;
		if (word[0] >= 'A' && word[0] <= 'Z')
		{		
			if (word[1] >= 'A' && word[1] <= 'Z')
			{			
				for (int i = 2; i < word.length(); i++)
				{
					if (word[i] >= 65 && word[i] <= 90)
					{
						flag = 1;
					}
					else
					{
						flag = 0;
						break;
					}
				}
			}
			else
			{
				for (int i = 2; i < word.length(); i++)
				{
					if (word[i] >= 97 && word[i] <= 122)
					{
						flag = 1;
					}
					else
					{
						flag = 0;
						break;
					}
				}
			}
		}
		else
		{
			for (int i = 1; i < word.length(); i++)
			{
				if (word[i] >= 97 && word[i] <= 122)
				{
					flag = 1;
				}
				else
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag == 1)
			return true;
		else
			return false;
	}
};
#if 0
void main()
{
	Solution12 s;
	string a = "USA";
	string b = "Flag";
	string c = "you";
	string d = "youA";
	string e = "A";
	cout << s.detectCapitalUse(a) << endl;
	cout << s.detectCapitalUse(b) << endl;
	cout << s.detectCapitalUse(c) << endl;
	cout << s.detectCapitalUse(d) << endl;
	cout << s.detectCapitalUse(e) << endl;
	system("pause");
}
#else
#endif