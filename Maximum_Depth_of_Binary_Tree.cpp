#include <iostream>
#include<stack>
using namespace std;
/*二叉树、结构体相关练习  ----by 2017.04.22*/
//template < typename T > ;
struct TreeNode
{
	int val;
	TreeNode *right;
	TreeNode *left;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}//构造函数
};
class Solution14 {
public:
	int maxDepth(TreeNode* root) {
		if (root==NULL)
		{
			return 0;
		}
		int a = maxDepth(root->left);
		int b = maxDepth(root->right);
		if (a > b)
		{
			return a + 1;
		}
		else
			return b + 1;
	}
};
class Solution14_2 {//中序遍历
public:
	int maxDepth(TreeNode* root) {
		TreeNode *p = root;
		stack<TreeNode*> s;
		int sum = 0;
		while (!s.empty() || p!=NULL)
		{
			while (p!=NULL)
			{
				s.push(p);
				p = p->left;
			}
			if (!s.empty())
			{
				p = s.top();
				s.pop();
				cout << p -> val << endl;
				p = p->right;
			}
		}
		return 0;
	}
};
class Solution14_3 {//前序遍历
public:
	int maxDepth(TreeNode* root) {
		TreeNode *p = root;
		stack<TreeNode*> s;
		int sum = 0;
		int tempsum = 0;
		int flag = 0;
		while (!s.empty() || p != NULL)
		{
			if(p != NULL)
			{
				//cout << p->val << endl;
				s.push(p);
				p = p->left;
				//tempsum++;
			}
			else
			{
				p = s.top();
				s.pop();
				/*
				if (s.empty()==true)
				{
					flag++;
					if (tempsum>sum)
					{
						sum = tempsum;	
					}
					tempsum = flag;
				}
				*/
				p = p->right;
			}
		}
		return sum;
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
	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p2->right = p5;
	p3->left = NULL;
	p3->right = NULL;
	p4 -> left = NULL;
	p4->right = NULL;
	p5->left = NULL;
	p5->right=NULL;
	Solution14 s;
	cout << s.maxDepth(p1) << endl;
	cout << endl;

	Solution14_2 ss;
	ss.maxDepth(p1);
	cout << endl;

	Solution14_3 sss;
	cout << sss.maxDepth(p1) << endl;;
	cout << endl;

	system("pause");
}
#else
#endif
