#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h> 
using namespace std;
class Solution57 {
public:
	int maximumProduct(vector<int>& nums) {
		if (nums.size() == 3)
			return nums[0] * nums[1] * nums[2];
		sort(nums.begin(), nums.end());
		int l = nums.size() - 1;
		int a1 = nums[0] * nums[1] * nums[l];
		int a2 = nums[l] * nums[l-1] * nums[l-2];
		return a1 > a2 ? a1 : a2;
	}
};
#if 0
void main()
{
	Solution57 s;
	vector<int>a = { -1,-2,-3};
	cout << s.maximumProduct(a) << endl;
	system("pause");
}
#else
#endif