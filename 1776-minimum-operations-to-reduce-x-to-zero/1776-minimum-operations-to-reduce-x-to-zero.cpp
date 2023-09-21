class Solution {
public:
    int longestSubarrayWithSumX(vector<int>&nums,int t)
    {
        unordered_map<int,int> m;
        int sum = 0;
        int ans = -1;

        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];

            if(m[sum-t]>=1)
            {
                ans = max(ans , i - m[sum-t] + 1);
            }

            if(sum == t)
                ans = max(ans , i+1);

            m[sum] = i+1;
        }

        return ans;
        
    }
    int minOperations(vector<int>& nums, int x) 
    {
        int sum = 0;

        for(int i=0; i<nums.size(); i++)
            sum += nums[i];

        int target = sum - x;

        if(sum == x)
            return nums.size();

        int len = longestSubarrayWithSumX( nums , target );

        if(len == -1)
            return len;

        return nums.size()-len;
    }
};