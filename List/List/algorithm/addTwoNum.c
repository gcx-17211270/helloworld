#include "addTwoNum.h"

void addTwoSum_callback()
{
    int i = 4;
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* nodetmp = node;
    while (i > 0)
    {
        nodetmp->val = 10 - i;
        struct ListNode* next = (struct ListNode*)malloc(sizeof(struct ListNode));
        nodetmp->next = next;
        nodetmp = next;
        i--;
    }
    free(nodetmp);
    nodetmp = node;
    struct ListNode* result = addTwoNumbers(node, node);
    nodetmp = result;
    while (nodetmp->next != (void*)0)
    {
        printf("%d\n", nodetmp->val);
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* temp1 = l1, * temp2 = l2;
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node2 = node;
    int cl = 0;
    while (temp1 != NULL || temp2 != NULL || cl != 0)
    {
        if (temp1 == NULL && temp2 == NULL)
        {
            node->val = 1;
            cl = 0;
        }
        else if (temp1 == NULL)
        {
            node->val = temp2->val;
            node->val += cl;
            cl = 0;
            temp2 = temp2->next;
        }
        else if (temp2 == NULL)
        {
            node->val = temp1->val;
            node->val += cl;
            cl = 0;
            temp1 = temp1->next;
        }
        else
        {
            node->val = (temp1->val + temp2->val) % 10;
            node->val += cl;
            cl = (temp1->val + temp2->val) / 10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        struct ListNode* next = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->next = next;
        node = next;
    }
    //free(node);
    return node2;
}