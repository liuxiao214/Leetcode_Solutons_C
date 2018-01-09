#include <iostream>
#include <stack>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution118 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;
		stack<ListNode*>a;
		stack < ListNode* > b;
		while (headA != NULL)	
		{
			a.push(headA);
			headA = headA->next;
		}
		while (headB != NULL)
		{
			b.push(headB);
			headB = headB->next;
		}
		ListNode *pub=NULL;
		while (!a.empty() && !b.empty())
		{
			if (a.top() != b.top())
				return pub;
			else
			{
				pub = a.top();
				a.pop();
				b.pop();
			}		
		}
		return pub;
	}
};
class Solution118_1 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;
		ListNode *pa = headA;
		ListNode *pb = headB;
		while (pa!=pb)
		{
			pa = pa->next;
			pb = pb->next;
			if (pb == pa)
				return pa;
			if (pa == NULL)
				pa = headA;
			if (pb == NULL)
				pb = headB;
		}
		return pa;
	}
};
class Solution118_2 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;
		ListNode *pa = headA;
		ListNode *pb = headB;
		while (pa != pb)
		{
			pa = pa?pa->next:headB;
			pb = pb?pb->next:headA;
		}
		return pa;
	}
};
#if 0
void main()
{
	Solution118_2 s;
	ListNode *p1 = new ListNode(8);
	ListNode *p2 = new ListNode(9);

	ListNode *t1 = new ListNode(10);
	ListNode *t2 = new ListNode(11);

	ListNode *q1 = new ListNode(3);
	ListNode *q2 = new ListNode(4);
	ListNode *q3 = new ListNode(5);

	p1->next = p2;
	p2->next = t1;
	t1->next = t2;
	t2->next = NULL;

	q1->next = q2;
	q2->next = q3;
	q3->next = t1;

	ListNode *t = s.getIntersectionNode(p1, q1);
	cout << t->val << endl;

	system("pause");
}
#else
#endif