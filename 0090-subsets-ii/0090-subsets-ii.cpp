class Solution {
public:
    set<vector<int>> ans;

    void sub(vector<int>& nums , vector<int>& v ,int i)
    {
        if(i==nums.size())
        {
            ans.insert(v);
            return;
        }
        v.push_back(nums[i]);
        sub(nums,v,i+1);
        v.pop_back();
        sub(nums,v,i+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int> v;
        sort(nums.begin(),nums.end());
        sub(nums,v,0);
        vector<vector<int>> ANS;
        for(auto it : ans)
            ANS.push_back(it);
        return ANS; 
    }
};


