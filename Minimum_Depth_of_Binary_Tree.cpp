#include <iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};                                                    
class Solution108 {
public:
	int subdepth(TreeNode *p)
	{	
		int dep = 1;
		if (p->left == NULL && p->right == NULL)
			return 1;
		else if (p->left == NULL && p->right != NULL)
			return dep + subdepth(p->right);
		else if (p->left != NULL && p->right == NULL)
			return dep + subdepth(p->left);
		else
		{
			int dleft = dep + subdepth(p->left);
			int dright = dep + subdepth(p->right);
			return dleft < dright ? dleft : dright;
		}
	}
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		return subdepth(root);
	}
};
class Solution108_1 {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int dl=minDepth(root->left);
		int dr=minDepth(root->right);
		if (dl == 0)
			return dr + 1;
		if (dr == 0)
			return dl + 1;
		return dl < dr ? dl+1 : dr+1;
	}
};
class Solution108_2 {//³¬Ê±
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL)
			return 1 + minDepth(root->right);
		if (root->right == NULL)
			return 1 + minDepth(root->left);
		return minDepth(root->left)<minDepth(root->right) ? minDepth(root->left)+1 : minDepth(root->right)+1;
	}
};
#if 0
void main()
{
	Solution108_2 s;
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	TreeNode *p4 = new TreeNode(4);
	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p2->right = NULL;
	p3->left = NULL;
	p3->right = NULL;
	p4->left = NULL;
	p4->right = NULL;
	cout<<s.minDepth(p1)<<endl;
	system("pause");
}
#else
#endif