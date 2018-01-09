#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
class Solution39_1 {
public:
	string tree2str(TreeNode* t) {
		if (t == NULL)
		{
			return "";
		}
		string s;
		stringstream stream;
		stream << t->val;
		s = stream.str();
		if (t->left!=NULL)
		{
			s = s + "(" + tree2str(t->left) + ")";
		}
		else if (t->right!=NULL)
		{
			s = s + "()";
		}
		if (t->right!=NULL)
		{
			s = s + "(" + tree2str(t -> right) + ")";
		}
		return s;
	}
};
class Solution39 {
public:
	string tree2str(TreeNode* t) {
		if (t == NULL)
		{
			return NULL;
		}
		stack<TreeNode*>s;
		TreeNode *p = t;
		string str;
		while (!s.empty() || p!=NULL)
		{
			while (p!=NULL)
			{
				s.push(p);
				//Ç°Ðò±éÀú
				stringstream stream;
				stream << p->val;
				string s1 = stream.str();
				str.append(s1);
				string s2 = "()";
				str.append(s2);
				str.append(s2);
				p = p->left;
			}
			if (!s.empty())
			{
				p = s.top();
				s.pop();
				p = p->right;
			}
		}
		return "22";
	}
};
#if 0
void main()
{
	Solution39_1 s;
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
	p4->right = NULL;
	p5->left = NULL;
	p5->right = NULL;
	p6->left = NULL;
	p6->right = NULL;
	string ss=s.tree2str(p1).c_str();
	cout << ss << endl;
	system("pause");
}
#else 
#endif
