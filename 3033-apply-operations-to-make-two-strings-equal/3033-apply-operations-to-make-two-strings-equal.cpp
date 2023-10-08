class Solution {
public:
    int minOperations(string s1, string s2, int x) 
    {   
        vector<int> nums;
        int y = 0;
        
        for(int i=0; i<s1.size(); i++)
        {
            if(s1[i]!=s2[i])
                nums.push_back(i);
        }
        
        int z = nums.size();
        if(z%2==1)
            return -1;
        
        if(nums.size()==0)
            return 0;

        vector<int> dp(nums.size()+1,10000000);
        dp[0]=0;

        for(int i=1; i<=nums.size(); i++)
        {
            dp[i] = dp[i-1]+x;
            if(i>=2)
                dp[i] = min(dp[i] , dp[i-2] + 2*(nums[i-1] - nums[i-2]));
        }

        return dp[nums.size()]/2;
    }
};