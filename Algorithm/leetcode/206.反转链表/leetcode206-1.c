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
/**
206. 反转链表
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/