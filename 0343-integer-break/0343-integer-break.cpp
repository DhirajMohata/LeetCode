class Solution {
public:
    int integerBreak(int n) 
    {
        vector<int> dp(n+1,1);
        dp[1] = 1;

        for(int i=2; i<=n; i++)
        {
            int x = n/i , temp = 1;
            int y = n%i;

            for(int j=0; j<i; j++)
            {
                if(y)
                {
                    temp *= x+1;
                    y--;
                }
                else
                    temp *= x;
            }

            dp[i] = max(dp[i-1], temp);
        }    
        return dp[n];
    }
};