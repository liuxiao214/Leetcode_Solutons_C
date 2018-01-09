#include <iostream>
#include <vector>
using namespace std;
class Solution9 {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int realstart = 0;
		int realend = 0;
		int reallenth = 0;
		int tempstart = 0;
		int tempend = 0;
		int templenth = 0;
		for (int i = 0; i < nums.size();i++)
		{			
			if (nums[i]==1)
			{
				tempend = i;
				templenth = templenth + 1;			
			}
			else
			{			
				tempstart = i + 1;
				tempend = i + 1;
				templenth = 0;
			}
			if (templenth > reallenth)
			{
				realstart = tempstart;
				realend = tempend;
				reallenth = templenth;
			}
		}
		return reallenth;
	}
};
#if 0
void main()
{
	Solution9 a;
	vector<int>s = {0,1,1,1,1,1,1,0,0,1,1,1,0,1,1,1,1};
	cout << a.findMaxConsecutiveOnes(s) << endl;
	system("pause");
}
#else
#endif