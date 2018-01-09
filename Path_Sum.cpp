#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};
class Solution103 {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;
		if (root->left==NULL && root->right==NULL && root->val == sum)
			return true;
		else if (root->left == NULL && root->right == NULL && root->val != sum)
			return false;
		else
			return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};
#if 0
void main()
{
	Solution103 s;
	TreeNode *p1 = new TreeNode(-2);
	TreeNode *p2 = new TreeNode(-3);
	/*
	TreeNode *p3 = new TreeNode(8);
	TreeNode *p4 = new TreeNode(11);
	TreeNode *p5 = new TreeNode(13);
	TreeNode *p6 = new TreeNode(4);
	TreeNode *p7 = new TreeNode(7);
	TreeNode *p8 = new TreeNode(2);*/
	p1->left = NULL;
	p1->right = p2;
	p2->left = NULL;
	p2->right = NULL;
	/*
	p3->left = p5;
	p3->right = p6;
	p4->left = p7;
	p4->right = p8;
	p5->left = NULL;
	p5->right = NULL;
	p6->left = NULL;
	p6->right = NULL;
	p7->left = NULL;
	p7->right = NULL;
	p8->left = NULL;
	p8->right = NULL;
	*/
	cout << s.hasPathSum(p1, -5) << endl;
	system("pause");
}
#else
#endif