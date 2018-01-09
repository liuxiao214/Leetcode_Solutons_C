#include <iostream>
#include <math.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
class Solution88 {
public:
	int TreeHigh(TreeNode *p)
	{
		if (p == NULL)
			return 0;
		if (p->left == NULL && p->right == NULL)
			return 1;
		int left=TreeHigh(p->left);
		int right=TreeHigh(p->right);
		return 1 + (left > right ? left : right);
	}
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		int b = abs(TreeHigh(root->left) - TreeHigh(root->right));
		return (b <= 1 && isBalanced(root->left) && isBalanced(root->right));
	}
};
class Solution88_1 {
public:
	int TreeHigh(TreeNode *p)
	{
		if (p == NULL)
			return 0;
		int left = TreeHigh(p->left);
		int right = TreeHigh(p->right);
		return 1 + (left > right ? left : right);
	}
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		int b = abs(TreeHigh(root->left) - TreeHigh(root->right));
		return (b <= 1 && isBalanced(root->left) && isBalanced(root->right));
	}
};
class Solution88_2 {
public:
	int TreeHigh(TreeNode *p)
	{
		if (p == NULL)
			return 0;
		int left = TreeHigh(p->left);
		if (left == -1)
			return -1;
		int right = TreeHigh(p->right);
		if (right == -1)
			return -1;
		if (abs(left - right) > 1)
			return -1;
		return 1 + (left > right ? left : right);
	}
	bool isBalanced(TreeNode* root) {
		return TreeHigh(root)!=-1;
	}
};
#if 0
void main()
{
	Solution88_2 s;
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	TreeNode *p4 = new TreeNode(5);
	p1->left = p2;
	p1->right = p3;
	p2->left = NULL;
	p2->right = p4;
	p3->left = NULL;
	p3->right = NULL;
	p4->left = NULL;
	p4->right = NULL;
	cout << s.isBalanced(p1) << endl;
	system("pause");
}
#else
#endif