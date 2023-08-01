class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        unordered_map<int,int> m;
        int i=0,j=nums.size()-1;
        for(int i=0;i<nums.size(); i++)
        {
            if(m[target-nums[i]]>=1)
            {
                ans.push_back(m[target-nums[i]]-1);
                ans.push_back(i);
                return ans;
            }
            m[nums[i]] = i+1;
        }
        return ans;
    }
};