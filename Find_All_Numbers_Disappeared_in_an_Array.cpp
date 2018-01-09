#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution13 {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int>flag(nums.size(),0);
		vector<int>newnums;
		for (int i = 0; i < nums.size();i++)
		{
			flag[nums[i]-1]++;
		}
		for (int i = 0; i < flag.size(); i++)
		{
			if (flag[i]==0)
			{
				newnums.push_back(i+1);
			}
		}
		return newnums;
	/*	int a = 0;
		for (int i = 0; i < nums.size();i++)
		{
			a ^= nums[i];
		}
		int b = 0;
		for (int i = 1; i <= nums.size();i++)
		{
			b ^= i;
		}
		int c = a^b;
		newnums.push_back(c);
		return newnums;*/
	}
};
class Solution13_13 {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int>newnums;
		for (int i = 0; i < nums.size(); i++)
		{
			nums[abs(nums[i]) - 1] = 0 - abs(nums[abs(nums[i]) - 1]);
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i]>0)
			{
				newnums.push_back(i+1);
			}
		}
		return newnums;
	}
};
#if 0
void main()
{
	Solution13_13 s;
	vector<int>a = { 4, 3, 2, 7, 8, 2, 3, 1 };
	vector<int>b = s.findDisappearedNumbers(a);
	for (int i = 0; i < b.size();i++)
	{
		cout << b[i] << endl;
	}
	system("pause");
}
#else
#endif