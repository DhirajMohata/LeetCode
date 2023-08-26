class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int ans = 0 , maxi = INT_MIN;
        
 
        for(int i=0; i<pairs.size(); i++)
        {
            if(pairs[i][0]>maxi)
            {
                maxi = pairs[i][1];
                ans++;
            }
        }
        
        return ans;
    }   
};