#include <iostream>
#include <vector>
using namespace std;
class Solution78 {
public:
	int rob(vector<int>& nums) {
		int f3 = 0;
		if (nums.size() == 1)
			return nums[0];
		else if (nums.size() == 0)
			return 0;
		else if (nums.size() == 2)
			return nums[0]>nums[1] ? nums[0] : nums[1];
		else
		{
			int f1 = nums[0];
			int f2 = nums[0]>nums[1] ? nums[0] : nums[1];
			int i = 3;
			while (i<=nums.size())
			{
				int temp = f1 + nums[i-1];
				f3 = f2 > temp ? f2 : temp;
				f1 = f2;
				f2 = f3;
				i++;
			}
		}
		return f3;
	}
};
class Solution78_1 {
public:
	int rob(vector<int>& nums) {
		int a = 0;
		int b = 0;
		for (int i = 0; i < nums.size();i++)
		{
			if (i % 2 == 0)
				a = (a + nums[i]) > b ? (a + nums[i]) : b;
			else
				b = (b + nums[i]) > a ? (b + nums[i]) : a;
		}
		return a > b ? a : b;
	}
};
#if 0
void main()
{
	Solution78_1 s;
	vector<int>a = { 6, 4, 9, 5, 8, 10 };
	cout << s.rob(a) << endl;
	system("pause");
}
#else 
#endif