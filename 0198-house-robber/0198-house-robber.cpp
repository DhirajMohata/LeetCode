class Solution {
public:

    int rob(vector<int>& nums) 
    {
        vector<int> dp(nums.size()+2,0);
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            if(i>=2)
                dp[i] = max(dp[i-1] , nums[i]+dp[i-2]);
            else
                dp[i] = max(nums[i-1],nums[i]);
        }     

        return dp[nums.size()-1];
    }
};