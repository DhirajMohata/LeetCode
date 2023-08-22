class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        // Keep track maximum freq element because we maximize our ans 
        unordered_map<int, int> freq;
        int j = 0, most = 0;

        for(int i = 0; i < n; i++) 
        {
            most = max(most, ++freq[nums[i]]);
            while(i - j - most >= k) 
            {
                freq[nums[j]]--;
                j++;
            }

            ans = max(ans, most);
        }
        return ans;
    }
};