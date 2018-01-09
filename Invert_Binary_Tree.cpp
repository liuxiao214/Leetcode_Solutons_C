#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
class Solution36 {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root==NULL)
		{
			return NULL;
		}
		invertTree(root->left);
		invertTree(root->right);
		swap(root->left, root->right);
		return root;
	}
};
class Solution36_1 {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
		{
			return NULL;
		}
		queue<TreeNode*>q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode *temp = q.front();
			q.pop();
			swap(temp->left, temp->right);
			if (temp->left != NULL)
			{
				q.push(temp->left);
			}
			if (temp->right != NULL)
			{
				q.push(temp->right);
			}
		}
		return root;
	}
};
#if 0
void main()
{
	Solution36_1 s;
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
	p4->right=NULL;
	p5->left = NULL;
	p5->right = NULL;
	p6->left = NULL;
	p6->right = NULL;
	s.invertTree(p1);
	cout << 1;
	system("pause");
}
#else 
#endif