class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int x = nums.size()/3;

        unordered_map<int,int> m;

        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;

        vector<int> ans;
        for(auto [key,val] : m)
        {
            if(val>x)
                ans.push_back(key);
        }    

        return ans;
    }
};