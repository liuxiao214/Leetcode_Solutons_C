#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution66 {
public:
	int findLHS(vector<int>& nums) {
		int max=0;
		map<int, int>a;
		for (int i = 0; i < nums.size();i++)
		{
			a[nums[i]]++;
		}
		map<int, int>::iterator temp;
		temp= a.begin();
		int prei = temp->first;
		int tempmax = 0;
		int tempnum = 0;
		for (pair<int,int>p:a)
		{			
			if (p.first==(prei+1))
			{
				tempmax = tempnum + p.second;
			}
			if (max<tempmax)
			{
				max = tempmax;
			}
			tempnum = p.second;
			prei = p.first;
		}
		return max;
	}
};
#if 0
void main()
{
	Solution66 s;
	vector<int>a = {1,5,3,7 };
	cout << s.findLHS(a) << endl;
	system("pause");
}
#else 
#endif