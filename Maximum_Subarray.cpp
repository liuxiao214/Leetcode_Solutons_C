#include <iostream>
#include <vector>
using namespace std;
class Solution72 {
public:
	int maxSubArray(vector<int>& nums) {
		int max = nums[0];
		int temp_max = max;
		int start = 0;
		int end = 0;
		int temp_start = 0;
		int temp_end = 0;
		for (int i = 1; i < nums.size();i++)
		{
			if (temp_max<=0)
			{
				temp_max = nums[i];
				temp_start = i;
			}
			else
			{
				temp_max = temp_max + nums[i];
				temp_end = i;
			}
			if (max<temp_max)
			{
				max = temp_max;
				start = temp_start;
				end = temp_end;
			}
		}
		return max;
	}
};
#if 0
void main()
{
	Solution72 s;
	vector<int>a = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << s.maxSubArray(a) << endl;
	system("pause");
}
#else
#endif