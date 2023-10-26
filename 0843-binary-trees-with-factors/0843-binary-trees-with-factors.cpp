class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        unordered_map<int,long long> m;

        for(auto it : arr)
            m[it] = 1;

        for(int i=0; i<arr.size(); i++)
        {
            for(int j=2; j<=sqrt(arr[i]); j++)
            {
                int y = arr[i]/j;

                if(arr[i]%j == 0 && m[j] >= 1 && m[y] >= 1)
                {
                    if(j!=y)
                        m[arr[i]] += 2 * m[j] * m[y];
                    else
                        m[arr[i]] += m[j] * m[y];
                }
            }
        }

        int ans = 0;

        for(auto [key,it] : m)
            ans = (ans + it)%1000000007;

        return ans;
    }
};