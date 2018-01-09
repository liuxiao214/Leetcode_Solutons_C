#include <iostream>
#include <vector>
using namespace std;
class Solution21 {
public:
	void moveZeroes(vector<int>& nums) {	
		int m = 0;
		int n = 0;
		for (int i = 0; i < nums.size();i++)
		{
			if (nums[i]==0)
			{
				m = i;
				int flag = 0;
				for (int j = m + 1; j < nums.size(); j++)
				{
					if (nums[j] != 0)
					{
						flag = 1;
						n = j;
						break;
					}
				}
				if (flag == 0)
				{
					break;
				}
				int temp = nums[m];
				nums[m] = nums[n];
				nums[n] = temp;		
			}
		}
	}
};
#if 0
void main()
{
	Solution21 s;
	vector<int>a = { 0, 0, 1 ,2,3,0};
	s.moveZeroes(a);
	for (int i = 0; i < a.size();i++)
	{
		cout << a[i] << endl;
	}
	system("pause");
}
#else
#endif
