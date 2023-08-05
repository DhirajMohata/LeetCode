/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;

        while(head)
        {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) 
    {
        if(head->next == NULL)
            return head;

        ListNode* temp = reverse(head);
        ListNode* te = temp;
        ListNode* ans = te;
        ListNode* res = te;
        temp = temp->next;

        ans->next = NULL;

        while(temp)
        {
            if(temp->val >= te->val)
            {
                ans->next = temp;
                ans = ans->next;
                te = temp;
                temp = temp->next;
                ans->next = NULL;   
            }
            else
                temp = temp->next;
        }

        return reverse(res);
    }
};