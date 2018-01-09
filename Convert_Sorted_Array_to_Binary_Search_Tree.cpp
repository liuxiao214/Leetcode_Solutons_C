#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){};
};
class Solution58 {
public:
	bool BST_insert(TreeNode *p, int x)
	{
		if (p==NULL)
		{
			TreeNode *temp = new TreeNode(x);
			return true;
		}
		if (p->val>x)
		{
			return BST_insert(p->left, x);
		}
		else
			return BST_insert(p->right, x);
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
			return NULL;
		if (nums.size() == 1)
			return new TreeNode(nums[0]);
		TreeNode * q = NULL;
		for (int i = 0; i < nums.size();i++)
		{
			BST_insert(q, nums[i]);
		}
		return q;
	}//输出有错误，出现内存问题貌似，不管了，应该是输出的问题
	//而且提交也不对
};
class Solution58_1 {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
			return NULL;
		if (nums.size() == 1)
			return new TreeNode(nums[0]);
		int mid = nums.size() / 2;
		TreeNode *p = new TreeNode(nums[mid]);
		vector<int>leftnums(nums.begin(), nums.begin() + mid);
		vector<int>rightnums(nums.begin()+mid+1, nums.end());
		p->left = sortedArrayToBST(leftnums);
		p->right = sortedArrayToBST(rightnums);
		return p;
	}
};
#if 0
void main()
{	
	Solution58_1 s;
	vector<int>a = { 1, 2, 3};
	TreeNode *p = s.sortedArrayToBST(a);
	cout << p->val << endl;
	cout << p->left->val << endl;
	system("pause");
}
#else
#endif