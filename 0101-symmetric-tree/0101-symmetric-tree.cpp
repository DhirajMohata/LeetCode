class Solution {
public:
    bool check(TreeNode* leftR,TreeNode* rightR)
    {
        if(leftR==NULL && rightR==NULL)
        {
            return true;
        }

        if(leftR==NULL || rightR==NULL)
        {
            return false;
        }

        bool ans1=false,ans2=false;

        if(leftR->val==rightR->val)
        {
            ans1=check(leftR->left,rightR->right);
        }

        if(leftR->val==rightR->val)
        {
            ans2=check(leftR->right,rightR->left);
        }

        if(ans1 && ans2)
            return true;

        return false;
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }

        return check(root->left,root->right);
    }
};