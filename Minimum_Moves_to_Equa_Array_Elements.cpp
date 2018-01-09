#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;
class Solution27 {
public:
	int minMoves(vector<int>& nums) {
		int step = 0;
		sort(nums.begin(), nums.end());
		for (int i = nums.size() - 1; i >0; i--)
		{
			step = step + (nums[i] - nums[i-1])*(nums.size()-i);
		}
		return step;
		/*
		int step = 0;
		vector<int>::iterator min = min_element(nums.begin(), nums.end());
		vector<int>::iterator max = max_element(nums.begin(), nums.end());
		int mymin = *min;
		int mymax = *max;
		while (mymin!=mymax)
		{
			for (int i = 0; i != distance(std::begin(nums), max) && i < nums.size(); i++)
			{
				nums[i]++;
				step++;
			}
			min = min_element(nums.begin(), nums.end());
			max = max_element(nums.begin(), nums.end());
			mymin = *min;
			mymax = *max;
		}
		return step;*/
	}
};
#if 0
void main()
{
	Solution27 s;
	vector<int> a = { 1, 4, 6,8 };
	cout << s.minMoves(a) << endl;
	system("pause");
}
#else
#endif