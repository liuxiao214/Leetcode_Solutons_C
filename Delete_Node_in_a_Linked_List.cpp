#include <iostream>
using namespace std;
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};
class Solution34
{
public:
	void deleteNode(ListNode* node) {
		*node = *node->next;
	}
};
#if 0
void main()
{
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = NULL;
	Solution34 s;
	s.deleteNode(p2);
	cout << p1->val << endl << p1->next->val << endl << p1->next->next->val << endl;
	system("pause");
}
#else
#endif

