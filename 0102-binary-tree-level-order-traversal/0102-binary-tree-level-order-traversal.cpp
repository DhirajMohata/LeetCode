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
    
    vector<vector<int>> level(TreeNode* root)
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == NULL)
            return ans;

        q.push(root);

        while(!q.empty())
        {
            vector<int> temp;
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* te = q.front();

                temp.push_back(te->val);
                if(te->left!=NULL) q.push(te->left);
                if(te->right!=NULL) q.push(te->right);

                q.pop();
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {  
        return level(root);
    }
};