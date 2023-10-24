/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) 
    {
        queue<TreeNode*> s;
        vector<int> ans;
        int x , temp;

        if(root != NULL)
            s.push(root);

        while(!s.empty())
        {
            x = s.size();
            temp = INT_MIN;
            while(x--)
            {
                TreeNode* te = s.front();   
                s.pop();
                if(te->left != NULL) s.push(te->left);
                if(te->right != NULL) s.push(te->right);

                temp = max(temp , te->val);
            }
            ans.push_back(temp);
        } 

        return ans;
    }
};