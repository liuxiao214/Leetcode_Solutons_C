#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};
class Solution99 {
public:
	bool hasCycle(ListNode *head) {
		ListNode *p = head;
		ListNode *q = head;
		while (p!=NULL && q!=NULL && q->next!=NULL)
		{
			p = p->next;
			q = q->next->next;
			if (p == q)
				return true;
		}
		return false;
	}
};
#if 0
void main()
{
	Solution99 s;
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(1);
	ListNode *p3 = new ListNode(1);
	ListNode *p4 = new ListNode(1);
	ListNode *p5 = new ListNode(1);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p2;
	cout << s.hasCycle(p1) << endl;
	system("pause");
}
#else
#endif