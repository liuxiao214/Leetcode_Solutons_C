#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution28 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int>::iterator n1 = unique(nums1.begin(), nums1.end());
		vector<int>::iterator n2 = unique(nums2.begin(), nums2.end());
		nums1.erase(n1, nums1.end());
		nums2.erase(n2, nums2.end());
		vector<int>same;
		int i = 0, j = 0;
		while (i<nums2.size()&&j<nums1.size())
		{
			if (nums1[j]==nums2[i])
			{
				same.push_back(nums2[i]);
				i++;
				j++;
			}
			else if (nums1[j] > nums2[i])
			{
				i++;
			}
			else
			{
				j++;
			}
		}
		return same;
	}
};
#if 0
void main()
{
	Solution28 s;
	vector<int>a1 = { 1, 2,2,2, 3, 4 };
	vector<int>a2 = { 1, 2 ,1,1};
	vector<int>b = s.intersection(a1, a2);
	for (int i = 0; i < b.size();i++)
	{
		cout << b[i] << endl;
	}
	//cout << b.size() << endl;
	system("pause");
}
#else
#endif