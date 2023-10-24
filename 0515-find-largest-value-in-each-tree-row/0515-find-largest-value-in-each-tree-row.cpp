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

        if(root != NULL)
            s.push(root);

        while(!s.empty())
        {
            int x = s.size();
            int temp = INT_MIN;
            while(x--)
            {
                TreeNode* te = s.front();   
                if(te->left != NULL) s.push(te->left);
                if(te->right != NULL) s.push(te->right);

                temp = max(temp , te->val);
                s.pop();
            }
            ans.push_back(temp);
        } 

        return ans;
    }
};