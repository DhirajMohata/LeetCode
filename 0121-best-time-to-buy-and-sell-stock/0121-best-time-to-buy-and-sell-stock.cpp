class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,maxi=prices[prices.size()-1];
        for(int i=prices.size()-2; i>=0; i--)
        {
            ans = max(ans , maxi - prices[i]);
            maxi = max(maxi,prices[i]);
        }
        return ans;
    }
};