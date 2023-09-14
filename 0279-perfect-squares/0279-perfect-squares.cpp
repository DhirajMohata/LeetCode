class Solution {
public:
    int numSquares(int n) 
    {
        vector<int> sqr;
        sqr.push_back(1);

        while(true)
        {
            long long temp = sqr.size()*sqr.size();
            long long N = n;

            if(temp<=N)
                sqr.push_back((int)temp);
            else
                break;
        }   

        vector<vector<int>> dp(sqr.size(),vector<int> (n+1,0));

        for(int i=1; i<=n; i++)
        {
            dp[0][i] = dp[0][i-1]+1;
        }

        for(int i=1; i<sqr.size(); i++)
        {
            for(int j=1; j<sqr[i]; j++)
                dp[i][j] = dp[i-1][j];

            for(int j=sqr[i]; j<=n; j++)
            {
                dp[i][j] = min(dp[i-1][j] , dp[i][j-sqr[i]]+1);
            }
        }

        return dp[sqr.size()-1][n];
    }
};