class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {    
        vector<int> x(nums.size(),INT_MAX);

        for(int i=1; i<nums.size(); i++)
            x[i] = min(x[i-1] , nums[i-1]);

        set<int> s;
        s.insert(nums[nums.size()-1]);

        for(int i=nums.size()-2; i>=1; i--)
        {
            if(x[i]+1 < nums[i])
            {
                auto it = s.lower_bound(x[i]+1);

                if(it != s.end() && (*it)<nums[i])
                    return true;
            }
            s.insert(nums[i]);
        }
        
        return false;
    }
};