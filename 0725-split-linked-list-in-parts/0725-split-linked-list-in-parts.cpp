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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*> ans;
        int x = 0;
        ListNode* temp = head;
        
        while(temp)
        {
            temp=temp->next;
            x++;
        }

        cout << x << " ";

        int mod = x%k;
        x = x/k;

        int y = x;

        cout << x << " " << mod << " ";
        

        for(int i=0; i<k; i++)
        {
            if(head)
            {
                y = x;
                if(mod!=0)
                {
                    y = y+1;
                    mod--;
                }
                ListNode* te = head;
                ans.push_back(te);
                head = head->next;
                while(head && y!=1)
                {
                    te = te->next;
                    head = head->next;
                    y--;
                }
                te->next = NULL;
            }
            else{
                ans.push_back(NULL);
            }
        }   
        return ans; 
    }
};