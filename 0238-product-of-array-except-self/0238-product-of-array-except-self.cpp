class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> pre,post;
        pre.push_back(nums[0]);
        post.push_back(nums[nums.size()-1]);
        int s = nums.size()-1;

        for(int i=1; i<nums.size(); i++)
        {
            pre.push_back(nums[i]*pre[i-1]);
            post.push_back(nums[s-i]*post[i-1]);
        }
        reverse(post.begin(), post.end());

        nums[0]=post[1];
        nums[s]=pre[s-1];
        
        for(int i=1; i<s; i++)
        {
            nums[i]=pre[i-1]*post[i+1];
        }
        return nums;
    }
};