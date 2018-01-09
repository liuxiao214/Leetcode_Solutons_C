#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution141 {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int>dup;
		if (nums.size() == 0)
			return dup;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size()-1;i++)
		{
			if (nums[i+1]==nums[i])
			{
				dup.push_back(nums[i]);
				i++;
			}
		}
		return dup;
	}
};
class Solution141_1 {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int>dup;
		if (nums.size() == 0)
			return dup;
		for (int i = 0; i < nums.size();)
		{
			if (nums[i] != nums[nums[i] - 1])
				swap(nums[i], nums[nums[i] - 1]);
			else
				i++;
		}
		for (int i = 0; i < nums.size();i++)
		{
			if (nums[i] != i + 1)
				dup.push_back(nums[i]);
		}
		return dup;
	}
};
class Solution141_2 {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int>dup;
		if (nums.size() == 0)
			return dup;
		for (int i = 0; i < nums.size(); i++)
		{
			nums[abs(nums[i]) - 1] = 0 - nums[abs(nums[i]) - 1];
			if (nums[abs(nums[i]) - 1]>0)
				dup.push_back(abs(nums[i]));
		}
		return dup;
	}
};
class Solution141_3 {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int>dup;
		if (nums.size() == 0)
			return dup;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[abs(nums[i]) - 1]<0)
				dup.push_back(abs(nums[i]));
			nums[abs(nums[i]) - 1] = 0 - nums[abs(nums[i]) - 1];
		}
		return dup;
	}
};
class Solution141_4 {
public://failed
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int>dup;
		if (nums.size() == 0)
			return dup;	
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i]==-1)
				dup.push_back(nums[i]);
			nums[nums[i] - 1] = -1;			
		}
		return dup;
	}
};
#if 0
void main()
{
	Solution141_3 s;
	vector<int>nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
	vector<int>dup = s.findDuplicates(nums);
	for (int i = 0; i < dup.size();i++)
	{
		cout << dup[i] << " ";
	}
	cout << endl;
	system("pause");
}
#else
#endif
