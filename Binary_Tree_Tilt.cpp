#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <math.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
class Solution40_1 {
public:
		int sum = 0;
		int sum_all(TreeNode *root)
		{
			if (root==NULL)
			{
				return 0;
			}
			int left = sum_all(root->left);//左子树之和
			int right = sum_all(root->right);//右子树之和
			sum = sum + abs(left - right);//累计左右子树的绝对差
			return left + right + root -> val;//返回该节点作为子树的所有值之和
		}
		int findTilt(TreeNode* root) {
			sum_all(root);
			return sum;
		}
};
class Solution40 {
public:
	int findTilt(TreeNode* root) {
		if (root==NULL)
		{
			return 0;
		}
		int sum = 0;
		if (root->left && root->right)
		{
			sum = abs(root->left->val - root->right->val);
		}
		else if (root->left)
		{
			sum = root->left->val;
		}
		else if (root->right)
		{
			sum = root->right->val;
		}
		else
			sum = 0;
		return sum + findTilt(root->left) + findTilt(root->right);
	}
};
#if 0
void main()
{
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	TreeNode *p4 = new TreeNode(4);
	TreeNode *p5 = new TreeNode(5);
	TreeNode *p6 = new TreeNode(6);
	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p2->right = p5;
	p3->left = p6;
	p3->right = NULL;
	p4->left = NULL;
	p4->right = NULL;
	p5->left = NULL;
	p5->right = NULL;
	p6->left = NULL;
	p6->right = NULL;
	Solution40 s;
	cout << s.findTilt(p1) << endl;
	system("pause");
}
#else
#endif