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
class Solution38 {
public:
	int getMinimumDifference(TreeNode* root) {
		if (root==NULL)
		{
			return 0;
		}
		stack<TreeNode*>s;
		TreeNode *p = root;
		TreeNode *q=p;
		int min = 1000000000;
		int flag = 0;
		while (!s.empty() || p!=NULL)
		{
			while (p != NULL)
			{
				s.push(p);
				p = p->left;
			}
			if (!s.empty())
			{
				p = s.top();
				s.pop();
				flag++;
				if (flag==1)
				{
					q = p;
				}
				else
				{
					if (min > p->val-q->val)
					{
						min = p->val - q->val;
					}
					q = p;
				}				
				p = p->right;
			}
		}
		return min;
	}
};
#if 0
void main()
{
	/*
	TreeNode *p1 = new TreeNode(4);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(6);
	TreeNode *p4 = new TreeNode(1);
	TreeNode *p5 = new TreeNode(3);
	TreeNode *p6 = new TreeNode(5);
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
	*/
	TreeNode *p1 = new TreeNode(5);
	TreeNode *p2 = new TreeNode(4);
	TreeNode *p3 = new TreeNode(7);
	p1->left = p2;
	p1->right = p3;
	p2->left = NULL;
	p2->right = NULL;
	p3->left = NULL;
	p3->right = NULL;
	Solution38 s;
	cout << s.getMinimumDifference(p1) << endl;
	system("pause");
}
#else
#endif