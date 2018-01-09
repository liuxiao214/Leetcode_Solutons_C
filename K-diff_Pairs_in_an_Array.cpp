#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class Solution126 {
public:
	int findPairs(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return 0;
		sort(nums.begin(), nums.end());
		int count = 0;
		if (k==0)
		{
			map<int,int>sum;
			for (int i = 0; i < nums.size();i++)
			{
				sum[nums[i]]++;
			}
			map<int, int>::iterator it;
			for (it = sum.begin(); it != sum.end(); it++)
			{
				if (it->second > 1)
					count++;
			}
			return count;
		}
		else
		{
			for (int i = 0; i < nums.size() - 1; i++)
			{
				if (nums[i + 1] == nums[i])
					continue;
				for (int j = i + 1; j < nums.size(); j++)
				{
					if (nums[j] - nums[i] == k)
					{
						count++;
						break;
					}
					if (nums[j] - nums[i] > k)
						break;
				}
			}
			return count;
		}
	}
};
class Solution126_1 {
public:
	int findPairs(vector<int>& nums, int k) {
		if (nums.size() == 0 || k<0)
			return 0;
		set<int>count;
		map<int, int>value;
		for (int i = 0; i < nums.size();i++)
		{
			if (value.count(nums[i] - k))
				count.insert(nums[i] - k);
			if (value.count(nums[i] + k))
				count.insert(nums[i]);
			value[nums[i]]++;
		}
		return count.size();
	}
};
#if 0
void main()
{
	Solution126_1 s;
	vector<int>a = { 1, 1, 3, 4, 5 };
	cout << s.findPairs(a, 2) << endl;
	system("pause");
}
#else
#endif