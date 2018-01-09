#include <iostream>
#include <vector>
using namespace std;
class Solution23 {
public:
	int distributeCandies(vector<int>& candies) {
		int alllen = candies.size();
		int kind = 0;
		vector<int>flag(200002, 0);
		for (int i = 0; i < alllen;i++)
		{
			if (candies[i]>=0)
			{
				flag[candies[i]] = 1;
			}
			else
				flag[100000+0-candies[i]] = 1;
		}
		for (int i = 0; i < flag.size(); i++)
		{
			if (flag[i]==1)
			{
				kind++;
			}
		}
		if (kind <= (alllen / 2))
		{
			return kind;
		}
		else
			return alllen / 2;
	}
};
#if 0
void main()
{
	Solution23 s;
	vector<int>a = { 1, 1, 2, 2, 3, 3 };
	cout << s.distributeCandies(a) << endl;
	system("pause");
}
#else
#endif