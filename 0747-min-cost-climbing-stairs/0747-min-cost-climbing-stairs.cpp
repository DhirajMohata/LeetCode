class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) 
    {
        vector<int> dp(nums.size()+1,0);

        int ans = 0;
        for(int i=2; i<=nums.size(); i++)
        {
            dp[i] = min(nums[i-2]+dp[i-2] , dp[i-1]+nums[i-1]);
        }

        return dp[nums.size()];
    }
};