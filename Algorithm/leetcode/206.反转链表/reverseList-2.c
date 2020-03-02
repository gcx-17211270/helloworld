/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
	if(!head) return NULL;
    struct ListNode* next = NULL;
    struct ListNode* temp = NULL;
    //int i = 0;

    while(head)
    {   
        temp = head->next;
        head->next = next;
        next = head;
        head = temp;
        //i++;
        //printf("%d ",i);
    }
    return next;
}
