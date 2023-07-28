class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans=0;

        for(int i=0; i<nums.size(); i++)
        {
            if(m[k-nums[i]]>=1)
            {
                ans++;
                m[k-nums[i]]--;
            }
            else
                m[nums[i]]++;
        }
        return ans;
    }
};