#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
class Solution85 {
public:
	vector<int> findMode(TreeNode* root) {
		vector<int>a;
		if (root == NULL)
			return a;
		if (root->left == NULL && root->right == NULL)
		{
			a.push_back(root->val);
			return a;
		}
		stack<TreeNode*>s;
		TreeNode *p = root;
		while (!s.empty()||p!=NULL)
		{
			while (p!=NULL)
			{
				s.push(p);
				p = p->left;
			}
			if (!s.empty())
			{
				p = s.top();
				a.push_back(p->val);
				s.pop();
				p = p->right;
			}
		}
		vector<int>b;
		int max = 1;
		int temp = 1;
		for (int i = 1; i < a.size();i++)
		{
			if (a[i] == a[i - 1])
			{
				temp++;
				if (i == a.size() - 1)
				{
					if (temp > max)
					{
						b.clear();
						max = temp;
						temp = 1;
						b.push_back(a[i - 1]);
					}
					if (temp == max)
					{
						temp = 1;
						b.push_back(a[i]);
					}
				}
			}
			else
			{
				if (temp==max)
				{
					b.push_back(a[i-1]);
				}
				if (temp > max)
				{
					b.clear();
					max = temp;					
					b.push_back(a[i-1]);
				}
				if (max == 1 && i == a.size() - 1)
				{
					b.push_back(a[i]);
				}
				temp = 1;
			}		
		}
		return b;
	}
};
class Solution85_1 {
public:
	vector<int> findMode(TreeNode* root) {
		vector<int>a;
		if (root == NULL)
			return a;
		stack<TreeNode*>s;
		map<int, int>m;
		TreeNode *p = root;
		int max = 0;
		while (!s.empty() || p != NULL)
		{
			while (p != NULL)
			{
				s.push(p);
				p = p->left;
			}
			if (!s.empty())
			{
				p = s.top();
				m[p->val]++;
				max = max > m[p->val] ? max : m[p->val];
				s.pop();
				p = p->right;
			}
		}
		for (auto i : m)
		{
			if (i.second == max)
				a.push_back(i.first);
		}
		return a;
	}
};
#if 0
void main()
{
	Solution85_1 s;
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	TreeNode *p4 = new TreeNode(4);
	TreeNode *p5 = new TreeNode(5);
	p1->left = NULL;
	p1->right = p2;
	p2->left = NULL;
	p2->right = p3;
	p3->left = NULL;
	p3->right = p4;
	p4->left = NULL;
	p4->right = p5;
	p5->left = NULL;
	p5->right = NULL;
	vector<int>a = s.findMode(p1);
	for (int i = 0; i < a.size();i++)
	{
		cout << a[i] << endl;
	}
	system("pause");
}
#else
#endif