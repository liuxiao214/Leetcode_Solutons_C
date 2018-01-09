#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};
class Solution75 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode *p = new ListNode(-1);
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *q = p;
		while (p1!=NULL && p2!=NULL)
		{
			if (p1->val > p2->val)
			{
				q->next = p2;
				q = q->next;
				p2 = p2->next;
			}
			else
			{
				q->next = p1;
				q = q->next;
				p1= p1->next;
			}
		}
		while (p1!=NULL)
		{
			q->next = p1;
			q = q->next;
			p1 = p1->next;
		}
		while (p2!=NULL)
		{
			q->next = p2;
			q = q->next;
			p2 = p2->next;
		}
		return p->next;
	}
};
class Solution75_1 {public:	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {		if (l1 == NULL)			return l2;		if (l2 == NULL)			return l1;		ListNode *p = new ListNode(-1);		ListNode *p1 = l1;		ListNode *p2 = l2;		ListNode *q = p;		while (p1 != NULL && p2 != NULL)		{			if (p1->val > p2->val)			{				q->next = p2;				q = q->next;				p2 = p2->next;			}			else			{				q->next = p1;				q = q->next;				p1 = p1->next;			}		}		if (p1 != NULL)			q->next = p1;		if (p2 != NULL)			q->next = p2;		return p->next;	}};
#if 0
void main()
{
	Solution75 s;
	ListNode *p1 = new ListNode(1);

	ListNode *q1 = new ListNode(2);

	p1->next = NULL;
	q1->next = NULL;

	ListNode *p = s.mergeTwoLists(p1, q1);
	cout << p->val << " " << p->next->val << endl;
	system("pause");
}
#else
#endif