class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) 
    {
        int ans = INT_MAX , n = nums.size();
        set<int> s;

        for(int i=n-x-1; i>=0; i--)
        {
            s.insert(nums[i+x]);
            auto x = s.lower_bound(nums[i]);
            if(x!=s.end()) ans = min(ans , *x-nums[i]);
            if(x!=s.begin()) ans = min(ans ,  nums[i]-*prev(x));
        }
        return ans;
    }
};