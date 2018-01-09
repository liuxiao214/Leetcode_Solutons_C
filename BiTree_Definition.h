#include <iostream>
using namespace std;
/*二叉树、结构体相关练习  ----by 2017.04.22*/
//template < typename T > ;
typedef struct Node
{
	int data;
	struct Node *leftchild;
	struct Node *rightchild;
}BiTreeNode;
void Initiate(BiTreeNode **root)//初始化
{
	*root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	(*root)->leftchild = NULL;
	(*root)->rightchild = NULL;
}
BiTreeNode *InsertLeftNode(BiTreeNode *curr, int x)//左插入节点
{
	BiTreeNode *temp, *snew;
	if (curr == NULL)
	{
		return NULL;
	}
	temp = curr->leftchild;
	snew = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	snew->data = x;
	snew->leftchild = temp;
	snew->rightchild = NULL;
	curr->leftchild = snew;
	return curr->leftchild;
}
BiTreeNode *InsertRightNode(BiTreeNode *curr, int x)//右插入节点
{
	BiTreeNode *temp, *snew;
	if (curr = NULL)
	{
		return NULL;
	}
	temp = curr->leftchild;
	snew = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	snew->data = x;
	snew->leftchild = NULL;
	snew->rightchild = temp;
	curr->rightchild = snew;
	return curr->rightchild;
}
BiTreeNode *DeleteLeftNode(BiTreeNode *curr)//左删除子树
{
	if (curr == NULL || curr->leftchild == NULL)
	{
		return NULL;
	}
	curr->leftchild = NULL;
	return curr;
}
BiTreeNode *DeleteRightNode(BiTreeNode *curr)//右删除子树
{
	if (curr == NULL || curr->rightchild == NULL)
	{
		return NULL;
	}
	curr->rightchild = NULL;
	return curr;
}
void myvisit(int x)
{
	cout << x << " ";
}
void PreOrder(BiTreeNode *root)//前序遍历
{
	if (root != NULL)
	{
		myvisit(root->data);
		PreOrder(root->leftchild);
		PreOrder(root->rightchild);
	}
}
void InOider(BiTreeNode *root)//中序遍历
{
	if (root != NULL)
	{
		InOider(root->leftchild);
		myvisit(root->data);
		InOider(root->rightchild);
	}
}
void PostOrder(BiTreeNode *root)//后序遍历
{
	if (root != NULL)
	{
		PostOrder(root->leftchild);
		PostOrder(root->rightchild);
		myvisit(root->data);
	}
}
void Destory(BiTreeNode **root)//撤销二叉树操作
{
	if ((*root)!=NULL && (*root)->leftchild==NULL)
	{
		Destory(&(*root)->leftchild);
	}
	if ((*root)!=NULL && (*root)->rightchild==NULL)
	{
		Destory(&(*root)->rightchild);
	}
	free(*root);
}
void PrintBiTree(BiTreeNode *root, int n)
{//逆时针旋转90度，打印二叉树root，n为缩进层数，初始值为0
	int i;
	if (root==NULL)
	{
		return ;
	}
	PrintBiTree(root->rightchild, n + 1);//遍历打印右子树
	//访问根节点
	for (i = 0; i < n - 1;i++)
	{
		cout << "  ";
	}
	if (n>0)
	{
		cout << "---"<<endl<<root->data;
	}
	PrintBiTree(root->leftchild, n + 1);//遍历打印左子树
}
BiTreeNode *Search(BiTreeNode *root, int data)//查找数据元素
{
	BiTreeNode *find = NULL;
	if (root!=NULL)
	{
		if (root->data==data)
		{
			find = root;
		}
		else
		{
			find = Search(root->leftchild, data);
			if (find==NULL)
			{
				find = Search(root->rightchild, data);
			}
		}
	}
	return find;
}
