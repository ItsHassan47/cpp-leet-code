#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insertStart(ListNode *&head, int value)
{
	ListNode *newNode = new ListNode(value);
	newNode->next = head;
	head = newNode;
}

void display(ListNode *head)
{
	while (head != nullptr) {
		cout << head->val << ' ';
		head = head->next;
	}
	cout << endl;
}

class Solution
{
	ListNode *head;
public:
	Solution() : head(nullptr) {}
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *p = l1;
		ListNode *q = l2;
		ListNode *sum = new ListNode;
		ListNode *cur = sum;
		int carry = 0;
		while (p != nullptr || q != nullptr) {
			int x = (p != nullptr) ? p->val : 0;
			int y = (q != nullptr) ? q->val : 0;
			int s = x + y + carry;
			carry = s / 10;
			cur->next = new ListNode(s % 10);
			cur = cur->next;
			if (p != nullptr)
				p = p->next;
			if (q != nullptr)
				q = q->next;
		}
		if (carry > 0) {
			cur->next = new ListNode(carry);
		}		
		return sum->next;
	}
};



int main()
{
	ListNode *l1 = nullptr;
	for (auto n : {3,4,2}) {
		insertStart(l1, n);
	}
	display(l1);

	ListNode *l2 = nullptr;
	for (auto n : {4,6,5}) {
		insertStart(l2, n);
	}
	display(l2);
	Solution s;
	ListNode *sum = s.addTwoNumbers(l1, l2);
	display(sum);
	return 0;
}