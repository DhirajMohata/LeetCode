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
        stack<vector<int>> s;

        if(root==NULL) return ans;
        q.push(root);

        while(!q.empty())
        {
            vector<int> te;
            int size = q.size();

            for(int i=0; i<size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                te.push_back(temp->val);
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            s.push(te);
        }

        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        return level(root);
    }
};