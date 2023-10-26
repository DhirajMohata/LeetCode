class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        unordered_map<int,long long> m;
        
        int ans = 0;

        for(auto it : arr)
            m[it] = 1;

        for(int i=0; i<arr.size(); i++)
        {
            for(int j=2; j<=sqrt(arr[i]); j++)
            {
                if(arr[i]%j == 0 && m[j] >= 1 && m[arr[i]/j] >= 1)
                {
                    if(j!=arr[i]/j)
                        m[arr[i]] += 2 * m[j] * m[arr[i]/j];
                    else
                        m[arr[i]] += m[j] * m[arr[i]/j];
                }
            }
            ans = (ans + m[arr[i]])%1000000007;
        }

        return ans;
    }
};