#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution25 {
public:
	int findContentChildren(vector<int> &g, vector<int>& s) {
		int glen = g.size();
		int slen = s.size();
		int sum = 0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int t = 0;
		for (int i = 0; i < glen;i++)
		{
			for (int j = t; j < slen;j++)
			{
				if (g[i]<=s[j])
				{
					sum++;
					t = j + 1;
					break;
				}
			}
		}
		return sum;
	}
};
#if 0
void main()
{
	Solution25 s;
	vector<int>a = { 1, 2, 3 };
	vector<int>b = { 1, 2 };
	cout << s.findContentChildren(a, b) << endl;
	system("pause");
}
#else
#endif