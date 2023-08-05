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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* temp = head;
        int n = 0,x=1;
        while(temp)
        {
            temp = temp->next;
            n++;
        }
        int y = n-k+1;
        ListNode* start = head;
        ListNode* end = head;

        while(x!=k)
        {
            start = start->next;
            x++;
        }
        x=1;

        while(x!=y)
        {
            end = end->next;
            x++;
        }

        int tempp = start->val;
        start->val = end->val;
        end->val = tempp;

        return head;
    }
};