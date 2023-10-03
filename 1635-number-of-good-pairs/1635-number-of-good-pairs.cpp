class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        vector<int> v(101,0);
        int ans = 0;

        for(int i=0; i<nums.size(); i++)
        {
            ans += v[nums[i]];
            v[nums[i]]++;
        }   

        return ans;
    }
};