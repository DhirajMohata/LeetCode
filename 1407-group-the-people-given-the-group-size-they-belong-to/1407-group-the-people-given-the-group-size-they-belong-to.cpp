class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<pair<int,int>> temp;

        for(int i=0; i<nums.size(); i++)
        {
            temp.push_back({nums[i],i});
        }

        sort(temp.begin(),temp.end());

        for(int i=0; i<nums.size(); i++)
        {
            vector<int> te;
            int x = temp[i].first;

            while(x--)
            {
                te.push_back(temp[i].second);
                i++;
            }
            ans.push_back(te);
            i--;
        }
        return ans;
    }
};