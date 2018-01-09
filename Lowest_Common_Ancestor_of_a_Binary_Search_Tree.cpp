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
class Solution76 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || p == NULL || q == NULL)
			return NULL;
		int imax = p->val > q->val ? p->val : q->val;
		int imin = p->val > q->val ? q->val : p->val;
		if (imax < root->val)
			return lowestCommonAncestor(root->left, p, q);
		else if (imin > root->val)
			return lowestCommonAncestor(root->right, p, q);
		else
			return root;
	}
};
class Solution76_1 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || p == NULL || q == NULL)
			return NULL;
		TreeNode *temp = root;
		while (1)
		{
			if (p->val < root->val && q->val < root->val)
				return lowestCommonAncestor(root->left, p, q);
			else if (p->val >root->val && q->val > root->val)
				return lowestCommonAncestor(root->right, p, q);
			else
				return root;
		}
	}
};
#if 0
void main()
{
	Solution76_1 s;
	TreeNode *p1 = new TreeNode(5);
	TreeNode *p2 = new TreeNode(3);
	TreeNode *p3 = new TreeNode(6);
	TreeNode *p4 = new TreeNode(2);
	TreeNode *p5 = new TreeNode(4);
	TreeNode *p6 = new TreeNode(1);
	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p2->right = p5;
	p3->left = NULL;
	p3->right=NULL;
	p4->left = p6;
	p4->right = NULL;
	p5->left = NULL;
	p5->right = NULL;
	p6->left = NULL;
	p6->right = NULL;
	TreeNode *q = s.lowestCommonAncestor(p1, p6, p5);
	cout << q->val << endl;
	system("pause");
}
#else
#endif