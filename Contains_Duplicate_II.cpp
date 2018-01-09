#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution113 {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		//³¬Ê±
		if (nums.size() <2)
			return false;
		for (int i = 0; i < nums.size();i++)
		{
			for (int j = i + 1; j<nums.size() && j <= i + k;j++)
			{
				if (nums[i] == nums[j])
					return true;
			}
		}
		return false;
	}
};
class Solution113_1 {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.size() < 2)
			return false;
		map<int, int>m;
		for (int i = 0; i < nums.size();i++)
		{
			if (m[nums[i]] != 0 && (i - m[nums[i]] + 1) <= k)
				return true;
			m[nums[i]] = i + 1;
		}
		return false;
	}
};
class Solution113_2 {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.size() < 2)
			return false;
		set<int>s;
		for (int i = 0; i < nums.size();i++)
		{
			if (i>k)
				s.erase(nums[i - k - 1]);
			if (s.find(nums[i]) != s.end())
				return true;
			s.insert(nums[i]);
		}
		return false;
	}
};
#if 0
void main()
{
	Solution113_2 s;
	vector<int>a = { 4,5,1,2,3,1};
	cout << s.containsNearbyDuplicate(a, 3) << endl;
	system("pause");
}
#else
#endif