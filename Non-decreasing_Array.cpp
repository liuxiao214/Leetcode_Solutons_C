#include <iostream>
#include <vector>

using namespace std;

class Solution136 {
public:
	bool checkPossibility(vector<int>& nums) {
		if (nums.size() < 2)
			return true;
		int count = 0;
		vector<int>temp = nums;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i]>nums[i + 1])
			{
				if (i != 0)
				{
					nums[i] = nums[i + 1];
					i-=2;
				}				
				count++;
			}
		}
		if (count<2)
			return true;
		count = 0;
		for (int i = 0; i < temp.size() - 1; i++)
		{
			if (temp[i]>temp[i + 1])
			{
				temp[i + 1] = temp[i];
				count++;
			}
		}
		if (count < 2)
			return true;
		return false;
	}
};
class Solution136_1 {
public:
	bool checkPossibility(vector<int>& nums) {
		if (nums.size() < 2)
			return true;
		int count = 0;
		for (int i = 1; i < nums.size() && count<2 ;i++)
		{
			if (nums[i-1]>nums[i])
			{
				count++;
				if (i == 1 || nums[i - 2] <= nums[i])
					nums[i - 1] = nums[i];
				else
					nums[i] = nums[i - 1];
			}
		}
		if (count < 2)
			return true;
		else
			return false;
	}
};
#if 0
void main()
{
	Solution136_1 s;
	vector<int>nums = { -1,4 ,2, 3};
	cout << s.checkPossibility(nums) << endl;
	system("pause");
}
#else
#endif