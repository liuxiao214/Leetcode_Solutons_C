#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){};
};
class Solution142 {
public:
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*>q;
		q.push(root);
		int result = root->val;
		while (!q.empty())
		{
			result = q.front()->val;
			int size = q.size();
			while (size--)
			{
				TreeNode *temp = q.front();
				q.pop();
				if (temp->left)
					q.push(temp->left);
				if (temp->right)
					q.push(temp->right);
			}	
		}
		return result;
	}
};
class Solution142_1 {
public:
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*>q;
		q.push(root);
		int result = root->val;
		while (!q.empty())
		{
			TreeNode *temp = q.front();
			result = temp->val;
			q.pop();
			if (temp->right)
				q.push(temp->right);
			if (temp->left)
				q.push(temp->left);					
		}
		return result;
	}
};
#if 0
void main()
{
	Solution142_1 s;
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	TreeNode *p4 = new TreeNode(4);
	TreeNode *p5 = new TreeNode(5);
	TreeNode *p6 = new TreeNode(6);
	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p2->right = NULL;
	p3->left = p6;
	p3->right = NULL;
	p4->left = p5;
	p4->right=NULL;
	p5->left = NULL;
	p5->right = NULL;
	p6->left = NULL;
	p6->right = NULL;
	cout << s.findBottomLeftValue(p1) << endl;
	system("pause");
}
#else
#endif