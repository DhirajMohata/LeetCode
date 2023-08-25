class Solution {
public: 
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ;
       vector<int> dp(amount+1,0) ; 
       for (int j  = 0; j < amount +1 ; j++){
            dp[j] = (j == 0) ? 0 : INT_MAX - 1;
       }
        vector<int> curr = dp ; 
        for (int i = 1; i < coins.size() + 1; i++) {
            for (int j = 1; j < amount + 1; j++) {
                if (coins[i - 1] > j)
                    curr[j] = 0 + dp[j];
                else
                    curr[j] = min(0 + dp[j], 1+curr[j-coins[i-1]]);
            }
            dp = curr; 
        }
        return (dp[amount]==INT_MAX-1)?-1:dp[amount];
        
    }
};