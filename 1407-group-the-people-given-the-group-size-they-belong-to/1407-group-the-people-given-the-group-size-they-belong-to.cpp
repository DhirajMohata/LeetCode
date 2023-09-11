class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> temp;

        for(int i=0; i<nums.size(); i++)
        {
            temp[nums[i]].push_back(i);
        }

        for(auto [val,key] : temp)
        {
            
            for(int i=0; i<key.size(); i++)
            {
                vector<int> te;
                int x = val;
                while(x--)
                {
                    te.push_back(key[i]);
                    i++;
                }
                ans.push_back(te);
                i--;
            }
        }
        return ans;
    }
};