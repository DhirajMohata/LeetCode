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
    ListNode* partition(ListNode* head, int target) 
    {
        if(head==NULL || head->next==NULL)
        {
            cout << "x" << " ";
            return head;
        }
        ListNode* ans = head;
        ListNode* point=head;
        ListNode* prevPoint=head;
        ListNode* startPoint=head;

        //if First element is greater then targer then we have to find the first smaller value then it and make it the first value of thr list
        if(head->val>=target)
        {
            startPoint = head;
            ListNode* temp=head;
            temp = temp->next;
            while(temp && temp->val>=target)
            {
                point = temp;
                if(temp->next==NULL)
                    return ans;
                temp=temp->next;
            }

            point->next = temp->next;
            temp->next = startPoint;
            prevPoint = temp;
            ans = temp;
            head = point->next;

        }
        else
        {
            // else we have to find the first greater or equal value
            head = head->next;
            while(head->val<target && head)
            {
                prevPoint=prevPoint->next;
                if(head->next==NULL)
                    return point;
                head = head->next;
            }

            startPoint = head;
            point = head;
            head = head->next;
        }
        
        while(head)
        {
            //if greater or equal value we move to next else we move the element just before the first greater value
            if(head->val < target)
            {
                point->next = head->next;
                head->next = startPoint;
                prevPoint->next = head;
                prevPoint = prevPoint->next;
                head = point->next;
            }
            else
            {
                cout << head->val << " ";
                point = head;
                head = head->next;
            }
        }

        return ans;
    }
};