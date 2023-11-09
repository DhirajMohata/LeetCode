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
    unordered_map<int,int> m;

    void pre(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        m[root->val]++;

        pre(root->left);
        pre(root->right);
    }

    vector<int> findMode(TreeNode* root) 
    {
        pre(root);

        vector<int> ans;
        int maxi = 0;
        for(auto [key,val] : m)
        {
            maxi = max(maxi , val);
        }

        for(auto [key,val] : m)
        {
            if(maxi == val)
                ans.push_back(key);
        }

        return ans;
    }
};