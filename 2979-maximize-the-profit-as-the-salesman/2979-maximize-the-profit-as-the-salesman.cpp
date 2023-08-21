class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) 
    {   
        vector<vector<pair<int,int>>> v(n);
        vector<int> dp(n,0);

        for(int i=0; i<offers.size(); i++)
        {
            v[offers[i][1]].push_back({offers[i][0],offers[i][2]});
        }
        
        for(int i=0; i<n; i++)
        {
            if(v[i].size()==0)
            {
                if(i==0)
                    dp[i]=0;
                else
                    dp[i]=dp[i-1];
            }
            for(auto it : v[i])
            {
                if(i==0)
                    dp[i] = max(dp[i] , it.second);
                else
                {
                    if(it.first != 0)
                    {
                        dp[i] = max(dp[i] , it.second + dp[it.first - 1]);
                    }
                    else
                    {
                        dp[i] = max(dp[i] , it.second);
                    }
                }
            }
            if(i!=0)
                dp[i] = max(dp[i],dp[i-1]);
        }
        return dp[n-1];
    }
};