class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& nums) 
    {
        unordered_map<int,vector<int>> m;

        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i][0]].push_back(nums[i][1]);
            m[nums[i][1]].push_back(nums[i][0]);
        }

        int temp = nums[0][0];
        for(auto [key,val] : m)
        {
            if(val.size() == 1)
            {
                temp = key;
                break;
            }
        }

        vector<int> ans;

        ans.push_back(temp);
        temp = m[temp][0];

        while(true)
        {
            ans.push_back(temp);
            if(m[temp].size() == 1)
                break;
            
            if(m[temp][0] == ans[ans.size()-2])
            {
                temp = m[temp][1];
            }
            else
            {
                temp = m[temp][0];   
            }
        }

        return ans;
    }
};