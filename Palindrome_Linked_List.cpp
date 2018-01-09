#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};
class Solution110 {
public:
	bool isPalindrome(ListNode* head) {
		vector<int>v;
		while (head!=NULL)
		{
			v.push_back(head->val);
			head = head->next;
		}
		for (int i = 0; i < v.size() / 2;i++)
		{
			if (v[i] != v[v.size() - i - 1])
				return false;
		}
		return true;
	}
};
class Solution110_1 {//设置快慢指针，翻转后一半列表
public:
	ListNode *reverselist(ListNode *head)
	{
		ListNode *pre = NULL;
		ListNode *next = NULL;
		while (head!=NULL)
		{
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return true;
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast->next!=NULL && fast->next->next!=NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		slow->next = reverselist(slow->next);
		slow = slow->next;
		while (slow!=NULL)
		{
			if (slow->val != head->val)
				return false;
			slow = slow->next;
			head = head->next;
		}
		return true;
	}
};
#if 0
void main()
{
	Solution110_1 s;
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(2);
	ListNode *p5 = new ListNode(1);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = NULL;
	cout << s.isPalindrome(p1) << endl;
	system("pause");
}
#else
#endif