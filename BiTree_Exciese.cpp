#include "BiTree_Definition.h"
using namespace std;
void main1()
{
	BiTreeNode *root, *p, *find;
	char x = 'E';
	Initiate(&root);
	p = InsertLeftNode(root, 1);
	p = InsertLeftNode(p, 2);
	p = InsertLeftNode(p, 3);
	p = InsertRightNode(p, 4);
	p = InsertRightNode(root->leftchild, 5);
	InsertRightNode(p, 6);
	InsertLeftNode(p, 7);
	PrintBiTree(root, 0);
	system("pause");
}