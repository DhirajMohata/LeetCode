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
    ListNode* mergeKLists(vector<ListNode*>& v) 
    {

        if(v.size() == 1)return v[0];
        if(v.size() == 0)return nullptr;

        ListNode* dummy=new ListNode(0);
        ListNode* ans = dummy;
        int flag=0;

        while(true)
        {
            int mini = 100000;
            int x;
            for(int i=0; i<v.size(); i++)
            {
                if(v[i]!=NULL)
                {
                    if(v[i]->val < mini)
                    {
                        x = i;
                        mini = v[i]->val;
                    }
                    flag=1;
                }
                
            }
            if(flag==0)
            {
                break;
            }
            flag=0;

            ans->next=v[x];
            ans=ans->next;
            v[x] = v[x]->next;
        }

        ListNode* result=dummy->next;
        return result;
    }
};