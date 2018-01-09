#include <iostream>
#include <vector>
using namespace std;
class Solution6 {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int>numss;
		for (int i = 0; i < findNums.size(); i++)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (findNums[i]==nums[j])
				{
					int k;
					for (k = j + 1; k < nums.size();k++)
					{
						if (nums[k]>nums[j])
						{
							numss.push_back(nums[k]);
							break;
						}
					}
					if (k==nums.size())
					{
						numss.push_back(-1);
					}
				}
			}
		}
		return numss;
	}
};
#if 0
void main()
{
	Solution6 s;
	vector<int>a = { 4, 1, 2 };
	vector<int>b = {1, 3, 4, 2};
	vector<int>c = s.nextGreaterElement(a, b);
	for (int i = 0; i < c.size();i++)
	{
		cout << c[i] << endl;
	}
	system("pause");
}
#else 
#endif