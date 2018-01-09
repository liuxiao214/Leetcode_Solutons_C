#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Solution33 {
public:
	int firstUniqChar(string s) {
		int fla = 0;
		if (s.length()==0)
		{
			return -1;
		}
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'A')
			{
				continue;
			}
			int flag = 0;
			for (int j = i + 1;j < s.length();j++)
			{
				if (s[i]==s[j])
				{
					s[j] = 'A';
					flag = 1;
					fla = 1;
				}
			}
			if (flag==0)
			{
				return i;
			}
		}
		if (fla==1)
		{
			return -1;
		}
	}
};
#if 0
void main()
{
	Solution33 s;
	cout << s.firstUniqChar("dddccdbba") << endl;
	system("pause");
}
#else
#endif