#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution53 {
public:
	int missingNumber(vector<int>& nums) {
		int origal = ((nums.size() + 1)*nums.size()) / 2;
		int now = 0;
		for (int i = 0; i < nums.size();i++)
		{
			now += nums[i];
		}
		return origal - now;
	}
};
class Solution53_1 {
public:
	int missingNumber(vector<int>& nums) {
		return ((nums.size() + 1)*nums.size()) / 2 - accumulate(nums.begin(), nums.end(), 0);
	}
};
class Solution53_2 {
public:
	int missingNumber(vector<int>& nums) {
		int s = nums.size();
		for (int i = 0; i < nums.size();i++)
		{
			s = s^i;
			s = s^nums[i];
		}
		return s;
	}
};
#if 0
void main()
{
	Solution53_2 s;
	vector<int>a = { 0, 1, 3 };
	cout << s.missingNumber(a) << endl;
	system("pause");
}
#else
#endif