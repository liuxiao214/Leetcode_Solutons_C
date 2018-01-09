#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution51 {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int>a;
		if (nums1.size()==0 || nums2.size()==0)
		{
			return a;
		}
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int i = 0, j = 0;
		while (i < nums2.size() && j < nums1.size())
		{
			if (nums2[i] == nums1[j])
			{
				a.push_back(nums2[i]);
				i++;
				j++;
			}
			else if (nums2[i]> nums1[j])
			{
				j++;
			}
			else
			{
				i++;
			}
		}
		return a;
	}
};
#if 0
void main()
{
	Solution51 s;
	vector<int>nums1 = { 1, 2, 2, };
	vector<int>nums2 = { 2, 2 };
	vector<int>a = s.intersect(nums1, nums2);
	for (int i = 0; i < a.size();i++)
	{
		cout << a[i] << endl;
	}
	system("pause");
}
#else
#endif