#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
class Solution87 {
public:
	void DFS(TreeNode *p, vector<string>&a, string s)
	{
		if (p->left == NULL && p->right == NULL)
		{
			a.push_back(s);
			return;
		}
		if (p->left != NULL)
			DFS(p->left, a, s + "->" + to_string(p->left->val));
		if (p->right != NULL)
			DFS(p->right, a, s + "->" + to_string(p->right->val));		
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string>path;
		if (root == NULL)
			return path;
		DFS(root, path, to_string(root->val));
		return path;
	}
};
#if 0
void main()
{
	Solution87 s;
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
	vector<string>a = s.binaryTreePaths(p1);
	for (int i = 0; i < a.size();i++)
	{
		cout << a[i] << endl;
	}
	system("pause");
}
#else
#endif