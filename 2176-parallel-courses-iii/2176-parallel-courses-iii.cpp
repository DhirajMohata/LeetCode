class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& nums, vector<int>& time) 
    {
        vector<int> dp = time;

        for(int i=0; i<nums.size(); i++)
        {
            dp[nums[i][1]-1] = max(dp[nums[i][1]-1] , dp[nums[i][0]-1] + time[nums[i][1]-1]);
        }

        for(int i=0; i<nums.size(); i++)
            swap(nums[i][0],nums[i][1]);

        sort(nums.begin() , nums.end());

        for(int i=0; i<nums.size(); i++)
            swap(nums[i][0],nums[i][1]);

        for(int i=nums.size()-1; i>=0; i--)
        {
            dp[nums[i][1]-1] = max(dp[nums[i][1]-1] , dp[nums[i][0]-1] + time[nums[i][1]-1]);
        }

        int ans = 0;

        for(int i=0; i<dp.size(); i++)
        {
            ans = max(ans , dp[i]);
        }
        return ans;
    }
};