/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode *head = NULL;
        ListNode *tail = NULL;
        while(l1 && l2)
        {
            //pick the smaller one
            ListNode *small = NULL;
            if(l1->val < l2->val)
            {
                small = l1;
                l1 = l1->next;
                small->next = NULL;
            }
            else
            {
                small = l2;
                l2 = l2->next;
                small->next = NULL;
            }
            if(!head)
            {
                head = small;
                tail = small;
            }
            else
            {
                tail->next = small;
                tail = small;
            }
        }
        tail-> next = l1 == NULL ? l2 : l1;
        return head;       
    }
};
