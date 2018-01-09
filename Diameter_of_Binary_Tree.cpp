#include <iostream>
#include <stack>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
class Solution56 {
public:
	int max = 0;
	int diameterOfBinaryTree(TreeNode* root) {
		depth(root);
		return max;
	}
	int depth(TreeNode *root)
	{
		if (root == NULL)
		{
			return -1;//不存在的节点，深度为-1，叶子节点，深度为0.
		}
		int left = depth(root->left);
		int right = depth(root->right);
		int temp = left + right + 2;
		if (temp>max)
		{
			max = temp;
		}
		return (left > right ? left : right) + 1;
	}
};
#if 0
void main()
{
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	p1->left = p2;
	p1->right = NULL;
	p2->left = p3;
	p2->right = NULL;
	p3->left = NULL;
	p3->right = NULL;
	Solution56 s;
	cout << s.diameterOfBinaryTree(p1)<<endl;
	system("pause");
}
#else
#endif