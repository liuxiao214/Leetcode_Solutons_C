#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution42 {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		int n = nums.size() / 2;
		if (nums[0] == nums[n])
		{
			return nums[0];
		}
		for (int i = 1; i < nums.size();i++)
		{
			if (nums[i]!=nums[i-1])
			{
				if (nums[i]==nums[i+n])
				{
					return nums[i];
				}
			}
		}
	}
};
class Solution42_1 {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size() / 2;
		return nums[n];
	}
};
#if 0
void main()
{
	Solution42_1 s;
	vector<int>a = { 1, 1,1,0,0 ,0,1};
	cout << s.majorityElement(a) << endl;
	system("pause");
}
#else
#endif