#include <iostream>
using namespace std;
/*���������ṹ�������ϰ  ----by 2017.04.22*/
//template < typename T > ;
typedef struct Node
{
	int data;
	struct Node *leftchild;
	struct Node *rightchild;
}BiTreeNode;
void Initiate(BiTreeNode **root)//��ʼ��
{
	*root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	(*root)->leftchild = NULL;
	(*root)->rightchild = NULL;
}
BiTreeNode *InsertLeftNode(BiTreeNode *curr, int x)//�����ڵ�
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
BiTreeNode *InsertRightNode(BiTreeNode *curr, int x)//�Ҳ���ڵ�
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
BiTreeNode *DeleteLeftNode(BiTreeNode *curr)//��ɾ������
{
	if (curr == NULL || curr->leftchild == NULL)
	{
		return NULL;
	}
	curr->leftchild = NULL;
	return curr;
}
BiTreeNode *DeleteRightNode(BiTreeNode *curr)//��ɾ������
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
void PreOrder(BiTreeNode *root)//ǰ�����
{
	if (root != NULL)
	{
		myvisit(root->data);
		PreOrder(root->leftchild);
		PreOrder(root->rightchild);
	}
}
void InOider(BiTreeNode *root)//�������
{
	if (root != NULL)
	{
		InOider(root->leftchild);
		myvisit(root->data);
		InOider(root->rightchild);
	}
}
void PostOrder(BiTreeNode *root)//�������
{
	if (root != NULL)
	{
		PostOrder(root->leftchild);
		PostOrder(root->rightchild);
		myvisit(root->data);
	}
}
void Destory(BiTreeNode **root)//��������������
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
{//��ʱ����ת90�ȣ���ӡ������root��nΪ������������ʼֵΪ0
	int i;
	if (root==NULL)
	{
		return ;
	}
	PrintBiTree(root->rightchild, n + 1);//������ӡ������
	//���ʸ��ڵ�
	for (i = 0; i < n - 1;i++)
	{
		cout << "  ";
	}
	if (n>0)
	{
		cout << "---"<<endl<<root->data;
	}
	PrintBiTree(root->leftchild, n + 1);//������ӡ������
}
BiTreeNode *Search(BiTreeNode *root, int data)//��������Ԫ��
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
