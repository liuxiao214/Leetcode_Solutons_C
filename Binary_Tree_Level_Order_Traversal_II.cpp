#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
class Solution69 {//失败
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>>a;
		if (root==NULL)
		{
			return a;
		}
		queue<TreeNode*>q;
		q.push(root);
		TreeNode *p = root;
		stack<TreeNode*>s;
		s.push(root);
		while (!q.empty())
		{
			p = q.front();
			q.pop();
			if (p->right)
			{
				q.push(p->right);				
			}			
			if (p->left)
			{
				q.push(p->left);				
			}
			s.push(p->right);
			s.push(p->left);
		}
		int level = log10(s.size()) / log10(2);
		int t = s.size();
		while (t>(pow(2,level)-1))
		{
			s.pop();
			t--;
		}
		for (int i = pow(2, level-1); i >= 1;i=i/2)
		{
			vector<int>mini;
			int j = i;
			while (j>0)
			{
				TreeNode *temp = s.top();
				s.pop();
				if (temp)
				{
					mini.push_back(temp->val);
				}
				j--;
			}
			a.push_back(mini);
		}
		return a;
	}
};
class Solution69_1 {
public:
	vector<vector<int>>a;
	void DFS(TreeNode *p, int level)
	{
		if (p == NULL)
			return;
		if (level==a.size())
		{
			a.push_back(vector<int>());
		}
		a[level].push_back(p->val);	
		DFS(p->left, level + 1);
		DFS(p->right, level + 1);
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		DFS(root, 0);
		return vector<vector<int>>(a.rbegin(),a.rend());
	}
};
class Solution69_2 {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>>a;
		if (root == NULL)
		{
			return a;
		}
		queue<TreeNode*>q;
		q.push(root);
		TreeNode *p = root;
		int level = 0;
		int l_size = 1;//记录每一层节点个数
		//没有写完，无法判断层数
		while (!q.empty())
		{
			vector<int>temp;
			while (l_size--)
			{
				p = q.front();
				q.pop();
				temp.push_back(p->val);
				if (p->left)
				{
					q.push(p->left);
				}
				if (p->right)
				{
					q.push(p->right);
				}			
			}
			l_size =q.size();
			a.push_back(temp);
		}	
		return vector<vector<int>>(a.rbegin(), a.rend());
	}
};
#if 0
void main()
{
	Solution69_2 s;
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	TreeNode *p4 = new TreeNode(4);
	TreeNode *p5 = new TreeNode(5);
	p1->left = p2;
	p1->right = NULL;
	p2->left = p3;
	p2->right = NULL;
	p3->left = p4;
	p3->right = NULL;
	p4->left = p5;
	p4->right = NULL;
	p5->left = NULL;
	p5->right = NULL;
	vector<vector<int>>a=s.levelOrderBottom(p1);
	for (int i = 0; i < a.size();i++)
	{
		for (int j = 0; j < a[i].size();j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
}
#else
#endif