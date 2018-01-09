#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution44 {
public:
	int longestPalindrome(string s) {
		vector<int>a(52, 0);
		for (int i = 0; i < s.length();i++)
		{
			if (s[i]>90)
			{
				a[s[i] - 'a']++;
			}
			else
			{
				a[26 + s[i] - 'A']++;
			}
		}
		int ssum = 0;
		int flag = 0;
		for (int i = 0; i < a.size();i++)
		{
			if (a[i]%2==1)
			{
				ssum += a[i]-1;
				flag = 1;
			}
			else
			{
				ssum += a[i];
			}
		}
		if (flag == 1)
		{
			return ssum + 1;
		}
		else
			return ssum;		
	}
};
#if 0
void main()
{
	Solution44 s;
	cout << s.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") << endl;
	system("pause");
}
#else 
#endif