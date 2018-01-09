#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
class Solution45 {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1)
		{
			return false;
		}
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size();i++)
		{
			if (nums[i] == nums[i - 1])
			{
				return true;
			}
		}
		return false;
	}
};
class Solution45_1 {
public:
	bool containsDuplicate(vector<int>& nums) {
		return set<int>(nums.begin(), nums.end()).size() < nums.size();
	}
};
#if 0
void main()
{
	Solution45_1 s;
	vector<int>a = { 1, 2, 3, 4 };
	vector<int>b = { 1, 1, 2, 2, 2, 3, 3 };
	cout << s.containsDuplicate(a) << endl;
	cout << s.containsDuplicate(b) << endl;
	system("pause");
}
#else
#endif