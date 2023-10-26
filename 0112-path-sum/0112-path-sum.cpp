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
    int sum = 0;
    bool ans = false;
    int size = 0;
    void pre(TreeNode* root , int target)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(sum + root->val == target)
                ans = true;
            
            return;
        }

        sum += root -> val;

        if(root->left != NULL)
            pre(root -> left , target);
        if(root->right != NULL)
            pre(root -> right , target);

        sum -= root -> val;
    }

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root == NULL)
            return false;

        pre(root , targetSum);   
        
        return ans;
    }
};