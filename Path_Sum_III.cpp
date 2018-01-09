#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
class Solution71 {
public:
	int path_sum(TreeNode *p,int sum)
	{
		int res = 0;
 		if (p == NULL)
			return res;
		if (sum == p->val)
			res++;
		res = res + path_sum(p->left, sum - p->val);
		res = res + path_sum(p->right, sum - p->val);
		return res;
	}
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return 0;
		return path_sum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
};
#if 0
void main()
{
	Solution71 s;
	TreeNode *p1 = new TreeNode(10);
	TreeNode *p2 = new TreeNode(5);
	TreeNode *p3 = new TreeNode(-3);
	TreeNode *p4 = new TreeNode(11);
	TreeNode *p5 = new TreeNode(3);
	TreeNode *p6 = new TreeNode(2);
	TreeNode *p7 = new TreeNode(1);
	p1->left = p2;
	p1->right = p3;
	p2->left = p5;
	p2->right = p6;
	p3->left = p4;
	p3->right=NULL;
	p4->left = NULL;
	p4->right = NULL;
	p5->left = NULL;
	p5->right = NULL;
	p6->left = p7;
	p6->right = NULL;
	p7->left = NULL;
	p7->right = NULL;
	cout << s.pathSum(p1, 8) << endl;
	system("pause");
}
#else
#endif