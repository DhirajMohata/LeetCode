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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* ans = head;
        ListNode* prev1=head;
        ListNode* prev = head;
        int x = 0;

        head = head->next;

        while(true)
        {
            x=0;
            while(head && prev->val == head->val)
            {
                prev->next = head->next;
                head = prev->next;
                x=1;
            }

            if(x==0)
            {
                break;
            }

            ans = head;
            prev=head;
            prev1=head;

            if(head!=NULL)
            {
                head = head->next;
            }
            else{
                break;
            }
        }
        int y=0;

        while(head)
        {
            if(prev->val == head->val)
            {
                prev->next = head->next;
                head = prev->next;
                y=1;
            }
            else
            {
                if(y==1)
                {
                    prev1->next = head;
                    prev=prev1;
                    y=0;
                }
                else
                {
                    prev1 = prev;
                    prev = prev->next;
                    head = head->next;
                }
            }
        }
        if(y==1)
        {
            prev1->next = head;
            prev=prev1;
        }

        return ans;
    }
};