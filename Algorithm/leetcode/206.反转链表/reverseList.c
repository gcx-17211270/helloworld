/**
*Definition for singly-linked list
*struct ListNode
{
	int val;
	struct ListNode *next;
}
*/

struct ListNode* reverseList(struct ListNode* head) {
	if (!head) return NULL;
	struct ListNode *lists[40960];
	int l = 0;
	while (head) {
		lists[l++] = head;
		head = head->next;
	}
	head = lists[--l];
	while (l > 0) {
		lists[l]->next = lists[l - 1];
		l--;
	}
	lists[0]->next = NULL;
	return head;
}
