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
    ListNode* partition(ListNode* head, int x) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* start = NULL;
        ListNode* s = NULL;
        ListNode* end = NULL;
        ListNode* e = NULL;

        while(head)
        {
            ListNode* temp = new ListNode(head->val);
            if(head->val<x)
            {
                if(start==NULL)
                {
                    start=temp;
                    s = start;
                }
                else
                {
                    start->next=temp;
                    start = start->next;
                }
                cout << start->val << " l " ;
            }
            else
            {
                if(end==NULL)
                {
                    end=temp;
                    e = end;
                }
                else
                {
                    end->next=temp;
                    end = end->next;
                }
                cout << end->val << " e ";
            }
            head = head->next;
        }

        if(s==NULL)
            return e;

        start->next = e;

        return s;
    }
};