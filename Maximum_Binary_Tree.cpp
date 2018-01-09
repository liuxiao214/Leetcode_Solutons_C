#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution137 {
public:
	int findmax(vector<int>nums,int start,int end,int &max)
	{
		if (start == end)
			return -1;
		int index = start;
		max = nums[start];
		for (int i = start + 1; i < end;i++)
		{
			if (nums[i]>max)
			{
				max = nums[i];
				index = i;
			}
		}
		return index;
	}
	TreeNode* getsubtree(vector<int>& nums,int start,int end)
	{
		int max;
		int index = findmax(nums,start,end,max);
		if (index==-1)
			return NULL;	
		else
		{
			TreeNode *tempnode = new TreeNode(max);
			tempnode->left = getsubtree(nums, start, index);
			tempnode->right = getsubtree(nums, index + 1, end);
			return tempnode;
		}					
	}
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return getsubtree(nums, 0, nums.size());
	}
};

class Solution137_1 {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		vector<TreeNode*>store;
		for (int i = 0; i < nums.size();i++)
		{
			TreeNode *cur = new TreeNode(nums[i]);
			while (store.size()!=0 && store.back()->val<nums[i])
			{
				cur->left = store.back();
				store.pop_back();
			}
			if (store.size()!=0)
			{
				store.back()->right = cur;
			}
			store.push_back(cur);
		}
		return store.front();
	}
};

class Solution137_2 {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		stack<TreeNode*>store;
		for (int i = 0; i < nums.size(); i++)
		{
			TreeNode *cur = new TreeNode(nums[i]);
			while (!store.empty() && store.top()->val < nums[i])
			{
				cur->left = store.top();
				store.pop();
			}
			if (!store.empty())
			{
				store.top()->right = cur;
			}
			store.push(cur);
		}
		TreeNode *p = NULL;
		while (!store.empty())
		{
			p = store.top();
			store.pop();
		}
		return p;
	}
};
#if 0
void main()
{
	Solution137_2 s;
	vector<int>nums = { 3, 2, 1, 6, 0, 5 };
	TreeNode *p = s.constructMaximumBinaryTree(nums);
	cout << p->val << endl;
	cout << p->left->val << endl;
	cout << p->right->val << endl;
	system("pause");
}
#else
#endif
