#include <iostream>
#include <vector>
using namespace std;

class Solution93 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() == 0 && nums2.size() == 0)
			return 0;
		if (nums1.size() == 0)
		{
			int l = nums2.size() / 2;
			if (nums2.size() % 2 == 0)
				return double(nums2[l - 1] + nums2[l]) / 2;
			else
				return double(nums2[l]);
		}
		if (nums2.size() == 0)
		{
			int l = nums1.size() / 2;
			if (nums1.size() % 2 == 0)
				return double(nums1[l - 1] + nums1[l]) / 2;
			else
				return double(nums1[l]);
		}
		int ll;
		int lu = (nums1.size() + nums2.size()) % 2;
		if (lu == 0)
			ll = (nums1.size() + nums2.size()) / 2 - 1;
		else
			ll = (nums1.size() + nums2.size()) / 2;
		int i = 0, j = 0;
		while (i<nums1.size() && j<nums2.size())
		{
			if ((i+j)==ll)
			{
				if (lu == 0)
					return double(nums1[i] + nums2[j]) / 2;
				else
					return double(nums1[i]>nums2[j] ? nums2[j] : nums1[j]);
			}
			if (nums1[i]<=nums2[j])
				i++;
			else if (nums1[i] > nums2[j])
				j++;
		}
		while (i < nums1.size())
		{
			if ((i + j) == ll)
			{
				if (lu == 0)
					return double(nums1[i] + nums2[j]) / 2;
				else
					return double(nums1[i] > nums2[j] ? nums2[j] : nums1[j]);
			}
			i++;
		}
		while (j < nums2.size())
		{
			if ((i + j) == ll)
			{
				if (lu == 0)
					return double(nums1[i] + nums2[j]) / 2;
				else
					return double(nums1[i] > nums2[j] ? nums2[j] : nums1[j]);
			}
			j++;
		}
	}
//有问题，此法不通。
};
class Solution93_1 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() == 0 && nums2.size() == 0)
			return 0;
		if (nums1.size() == 0)
		{
			int l = nums2.size() / 2;
			if (nums2.size() % 2 == 0)
				return double(nums2[l - 1] + nums2[l]) / 2;
			else
				return double(nums2[l]);
		}
		if (nums2.size() == 0)
		{
			int l = nums1.size() / 2;
			if (nums1.size() % 2 == 0)
				return double(nums1[l - 1] + nums1[l]) / 2;
			else
				return double(nums1[l]);
		}
		int ll = (nums1.size() + nums2.size()) / 2;
		int lu = (nums1.size() + nums2.size()) % 2;
		int i = 0, j = 0;
		vector<int>a;
		while (i < nums1.size() && j < nums2.size())
		{
			if (nums1[i] <= nums2[j])
			{
				a.push_back(nums1[i]);
				i++;
			}
			else
			{
				a.push_back(nums2[j]);
				j++;
			}
		}
		while (i < nums1.size())
		{
			a.push_back(nums1[i]);
			i++;
		}
		while (j < nums2.size())
		{
			a.push_back(nums2[j]);
			j++;
		}
		if (lu == 0)
			return double(a[ll-1] + a[ll]) / 2;
		else
			return double(a[ll]);
	}
};
class Solution93_2 {
public:
	int getk(vector<int>l, int m, vector<int>r, int n, int k)
	{
		if (m < n)
			return getk(r, n, l, m, k);
		if (m == 0)
			return r[k - 1];
		if (k == 1)
			return l[0] < r[0] ? l[0] : r[0];
		int i = m < k / 2 ? m : k / 2;
		int j = n < k / 2 ? n : k / 2;
		//if (l[i - 1] > r[j - 1])
			//return getk(l, m, r + j, n - j, k - j);
		//else
			//return getk(l + i, m - i, r, n, k - i);
		return 0;
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		int k1 = (m + n + 1) / 2;
		int k2 = (m + n + 2) / 2;
		return (getk(nums1, m, nums2, n, k1) + getk(nums1, m, nums2, n, k2)) / 2.0;
	}
};
#if 0
void main()
{
	Solution93_1 s;
	vector<int>a1 = { 1,2 };
	vector<int>a2 = { 1,2};
	cout << s.findMedianSortedArrays(a1, a2) << endl;
	system("pause");
}
#else
#endif