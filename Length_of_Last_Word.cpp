#include <iostream>
#include <string>
using namespace std;

class Solution115 {
public:
	int lengthOfLastWord(string s) {
		if (s.length() == 0)
			return 0;	
		int first = -1;
		for (int i = s.length()-1; i >= 0; i--)
		{
			if (s[i] != ' ')
			{
				first = i;
				break;
			}
		}
		if (first == -1)
			return 0;
		int count = 0;
		for (int i = first; i >=0 ; i--)
		{
			if (s[i] == ' ')
				break;
			else
				count++;
		}
		return count;
	}
};
class Solution115_1 {
public:
	int lengthOfLastWord(string s) {
		int count = 0;
		int first = s.length() - 1;
		while (first >= 0 && s[first] == ' ')
			first--;
		while (first >= 0 && s[first] != ' ')
		{
			count++;
			first--;
		}
		return count;
	}
};
#if 0
void main()
{
	Solution115_1 s;
	cout << s.lengthOfLastWord("hello World") << endl;
	system("pause");
}
#else
#endif