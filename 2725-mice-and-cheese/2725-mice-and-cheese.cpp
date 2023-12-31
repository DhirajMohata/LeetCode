class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) 
    {
        int n = reward1.size(), ans = 0;
        vector<vector<int>> v;
        for(int i=0; i<n; i++) 
            v.push_back({reward1[i] - reward2[i], reward1[i], reward2[i]});
            
        sort(v.begin(), v.end(), greater<vector<int>>());
        
        for(int i=0; i<n; i++) 
        {
            if(k > 0)
            {
                ans += v[i][1];
                k--;
            }
            else 
                ans += v[i][2];
        }
        return ans;
    }
};