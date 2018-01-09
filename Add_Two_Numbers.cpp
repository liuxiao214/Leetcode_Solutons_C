#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};
class Solution91 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL)
			return NULL;
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *q = new ListNode(-1);
		ListNode *p = q;
		while (p1!=NULL && p2!=NULL)
		{
			ListNode *temp = new ListNode(p1->val + p2->val);
			p->next = temp;
			p = p->next;
			p1 = p1->next;
			p2 = p2->next;
		}
		if (p1!=NULL)
			p->next = p1;
		if (p2 != NULL)
			p->next = p2;
		int flag = 0;
		ListNode *t = q->next;
		while (t!=NULL)
		{
			t->val = t->val + flag;
			if (t->val>= 10)
			{			
				t->val = t->val % 10;
				flag = 1;
			}
			else
				flag = 0;	
			if (flag == 1 && t->next==NULL)
			{
				ListNode *m = new ListNode(1);
				t->next = m;
				break;
			}
			t = t->next;
		}
		return q->next;
	}
};
class Solution91_1 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL)
			return NULL;
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *q = new ListNode(-1);
		ListNode *p = q;
		int flag = 0;
		while (p1 != NULL && p2 != NULL)
		{
			ListNode *temp = new ListNode(p1->val + p2->val + flag);
			if (temp->val >= 10)
			{
				temp->val = temp->val % 10;
				flag = 1;
			}
			else
				flag = 0;
			p->next = temp;
			p = p->next;
			if (flag == 1 && p1->next == NULL && p2->next==NULL)
			{
				ListNode *x = new ListNode(1);
				p->next = x;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		while (p1 != NULL)
		{
			p1->val = p1->val + flag;
			if (p1->val >= 10)
			{
				p1->val = p1->val % 10;
				flag = 1;
			}
			else
				flag = 0;
			p->next = p1;
			p = p->next;
			if (flag == 1 && p1->next==NULL)
			{
				ListNode *x = new ListNode(1);
				p->next = x;
				break;
			}			
			p1 = p1->next;		
		}
		while (p2 != NULL)
		{
			p2->val = p2->val + flag;
			if (p2->val >= 10)
			{
				p2->val = p2->val % 10;
				flag = 1;
			}
			else
				flag = 0;
			p->next = p2;
			p = p->next;
			if (flag == 1 && p2->next == NULL)
			{
				ListNode *x = new ListNode(1);
				p->next = x;
				break;
			}
			p2 = p2->next;			
		}
		return q->next;
	}
};
class Solution91_2 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL)
			return NULL;
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *q = new ListNode(-1);
		ListNode *p = q;
		int sum = 0;
		while (p1 != NULL || p2 != NULL)
		{
			sum = sum / 10;
			if (p1 != NULL)
			{
				sum = sum + p1->val;
				p1 = p1->next;
			}
			if (p2 != NULL)
			{
				sum = sum + p2->val;
				p2 = p2->next;
			}
			p->next = new ListNode(sum % 10);
			p = p->next;
		}
		if (sum / 10 == 1)
			p->next = new ListNode(1);
		return q->next;
	}
};
class Solution91_3 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL)
			return NULL;
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *q = new ListNode(-1);
		ListNode *p = q;
		int flag = 0;
		while (p1 || p2 || flag)
		{
			int sum = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + flag;
			p->next = new ListNode(sum % 10);
			p = p->next;
			flag = sum / 10;
			p1 = p1 ? p1->next : p1;
			p2 = p2 ? p2->next : p2;
		}
		return q->next;
	}
};
#if 0
void main()
{
	Solution91_3 s;
	ListNode *p1 = new ListNode(9);
	ListNode *p2 = new ListNode(9);
	ListNode *p3 = new ListNode(9);
	ListNode *q1 = new ListNode(1);
	ListNode *q2 = new ListNode(1);
	ListNode *q3 = new ListNode(1);
	p1->next = p2;
	p2->next = p3;
	p3->next = NULL;
	q1->next = q2;
	q2->next = q3;
	q3->next = NULL;
	ListNode *t = s.addTwoNumbers(p1, q1);
	cout << t->val << " " << t->next->val << " " << t->next->next->val << " " << t->next->next->next->val << endl;
	system("pause");
}
#else
#endif