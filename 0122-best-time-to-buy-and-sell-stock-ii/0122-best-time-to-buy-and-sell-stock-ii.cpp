class Solution {
public:
    int maxProfit(vector<int>& nums) 
    {
        int ans = 0 , x = nums[0];

        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]<x)
                x = nums[i];
            else
            {
                ans += nums[i] - x;
                x = nums[i];
            }
        }

        return ans;    
    }
};