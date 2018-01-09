#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution15 {
public:
	int arrayPairSum(vector<int>& nums) {
		int sum=0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size();i=i+2)
		{
			if (nums[i] > nums[i + 1])
				sum = sum + nums[i + 1];
			else
				sum = sum + nums[i];
		}
		/*
		for (int i = 0; i < nums.size();i++)
		{
			for (int j = i+1; j < nums.size();j++)
			{
				if (nums[j] < nums[i])
				{
					int temp = nums[i];
					nums[i] = nums[j];
					nums[j] = temp;
				}
			}
			if (i%2==1)
			{
				if (nums[i] > nums[i - 1])
				{
					sum = sum + nums[i - 1];
				}
				else
					sum = sum + nums[i];
			}
		}*/
		return sum;
	}
};
#if 0
void main()
{
	Solution15 s;
	vector<int>a = { 2, 3, 1, 4 ,-3,-1,-4,6};
	cout << s.arrayPairSum(a) << endl;
	system("pause");
}
#else
#endif