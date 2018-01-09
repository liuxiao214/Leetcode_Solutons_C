#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
class Solution49_1 {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL && t2 == NULL)
		{
			return NULL;
		}
		TreeNode *temp = new TreeNode((t1 ? t1->val : 0) + (t2 ? t2->val : 0));
		temp->left = mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
		temp->right = mergeTrees(t1 ? t1->right : NULL, t2 ? t2->right : NULL);
		return temp;
	}
};
class Solution49_2 {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL)
		{
			return t2;
		}
		if (t2 == NULL)
		{
			return t1;
		}
		TreeNode *temp = new TreeNode(t1->val+t2->val);
		temp->left = mergeTrees(t1->left,t2->left);
		temp->right = mergeTrees(t1->right,t2->right);
		return temp;
	}
};
class Solution49 {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1==NULL && t2==NULL)
		{
			return NULL;
		}
		if (t1 == NULL)
		{
			return t2;
		}
		if (t2 == NULL)
		{
			return t1;
		}
		TreeNode *p = new TreeNode(t1->val + t2->val);
		TreeNode *pp1=p,*pp2=p;
		queue<TreeNode*>q1,q2;
		q1.push(t1);
		q2.push(t2);
		int flag1 = 0;
		int flag2 = 0;
		while (!q1.empty() || !q2.empty())
		{
			TreeNode *temp1 = q1.front();
			TreeNode *temp2 = q2.front();
			q1.pop();
			q2.pop();
			q1.push(temp1->left);
			q2.push(temp2->left);
			q1.push(temp1->right);
			q2.push(temp2->right);
			if (temp1->left != NULL && temp2->left != NULL)
			{
				TreeNode *temp = new TreeNode(temp1->left->val + temp2->left->val);
				pp1->left = temp;
			}
			else if (temp1->left != NULL && temp2->left == NULL)
			{
				TreeNode *temp = new TreeNode(temp1->left->val);
				pp1->left = temp;
			}
			else if (temp1->left == NULL && temp2->left != NULL)
			{
				TreeNode *temp = new TreeNode(temp2->left->val);
				pp1->left = temp;
			}
			else
			{
				pp1->left = NULL;
			}
			if (temp1->right != NULL && temp2->right != NULL)
			{
				TreeNode *temp = new TreeNode(temp1->right->val + temp2->right->val);
				pp2->right = temp;
			}
			else if (temp1->right != NULL && temp2->right == NULL)
			{
				TreeNode *temp = new TreeNode(temp1->right->val);
				pp2->right = temp;
			}
			else if (temp1->right == NULL && temp2->right != NULL)
			{
				TreeNode *temp = new TreeNode(temp2->right->val);
				pp2->right = temp;
			}
			else
			{
				p->right = NULL;
			}
		}
		return p;
	}
};
#if 0
void main()
{
	Solution49_2 s;
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	p1->left = p2;
	p1->right = NULL;
	p2->left = NULL;
	p2->right = NULL;

	TreeNode *q1 = new TreeNode(3);
	TreeNode *q2 = new TreeNode(4);
	q1->left = NULL;
	q1->right = q2;
	q2->left = NULL;
	q2->right = NULL;
	TreeNode *q=s.mergeTrees(p1, q1);
	cout << q->val << " " << q->left->val << " " << q->right->val << endl;
	system("pause");
}
#else
#endif