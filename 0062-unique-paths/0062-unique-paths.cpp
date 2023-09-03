class Solution {
public:
    int ans = 0;
    int solve(int m,int n,vector<vector<int>>& dp)
    {
        if(1==m && 1==n)
        {
            ans++;
            return 1;
        }
        if(m<1 || n<1)
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];

        dp[m][n] = solve(m-1,n,dp) + solve(m,n-1,dp);
        return dp[m][n];
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        
        return solve(m,n,dp);
    }
};