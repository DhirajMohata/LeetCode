class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        vector<long long> dp(arr.size() , 1);
        unordered_map<int,int> m;

        for(int i=0; i<arr.size(); i++)
        {
            for(int j=2; j<=sqrt(arr[i]); j++)
            {
                int y = arr[i]/j;

                if(arr[i]%j == 0 && m[j] >= 1 && m[y] >= 1)
                {
                    if(j!=y)
                        dp[i] += 2 * dp[m[j]-1] * dp[m[y]-1];
                    else
                        dp[i] += dp[m[j]-1] * dp[m[y]-1];
                }
            }
            m[arr[i]] = i + 1;
        }

        int ans = 0;
        
        for(auto it : dp)
            ans = (ans + it)%1000000007;

        return ans;
    }
};