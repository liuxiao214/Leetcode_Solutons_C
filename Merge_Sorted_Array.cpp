#include <iostream>
#include <vector>
using namespace std;
class Solution114_0 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		//ʧ�ܣ�ԭ��������1�ռ��m+n�󣬿��ܴ�ܶ࣬����ʼ����ǰm��Ԫ�أ�
		//Ҳ����˵��ֻ�Ƚ�����1ǰm��
		if (m == 0)
			nums1 = nums2;
		else
		{
			vector<int>::iterator i = nums1.begin();
			vector<int>::iterator j = nums2.begin();
			while (i != nums1.begin() && j != nums2.end())
			{
				if (*i > *j)
				{
					i = nums1.insert(i, *j);
					j++;
				}
				i++;
			}
		}
	}
};
class Solution114 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int>nums;
		int i = 0, j = 0;
		while (i<m || j<n)
		{
			if (i<m && j<n)
			{
				if (nums1[i]<nums2[j])			
				{
					nums.push_back(nums1[i]);
					i++;
				}
				else
				{
					nums.push_back(nums2[j]);
					j++;
				}
			}
			else if (i<m)
			{
				nums.push_back(nums1[i]);
				i++;
			}
			else if (j<n)
			{
				nums.push_back(nums2[j]);
				j++;
			}
		}
		nums1 = nums;
	}
};
class Solution114_1 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int k;
		int i = m - 1, j = n - 1;
		for (k= m+n-1; k >= 0;k--)
		{
			if ((j < 0 || nums1[i] > nums2[j]) && i >= 0)
				nums1[k] = nums1[i--];
			else
				nums1[k] = nums2[j--];
		}
	}
};
#if 0
void main()
{
	Solution114_1 s;
	vector<int>nums1 = {3,5,8,10};
	vector<int>nums2 = {2,6 };
	s.merge(nums1, 3,nums2,2);
	for (int i = 0; i < nums1.size();i++)
	{
		cout << nums1[i] << endl;
	}
	system("pause");
}
#else
#endif