class Solution {
public:
    static bool cmp(string& a , string& b)
    {
        return a.size()<b.size();
    }
    
    int longestStrChain(vector<string>& nums) 
    {
        unordered_map<string,int> m;
        int ans = 1;

        sort(nums.begin(),nums.end() , cmp);

        for(int i=0; i<nums.size(); i++)
        {
            int longest = 1;
            for(int j=0; j<nums[i].size(); j++)
            {
                string temp = nums[i];
                temp.erase(j,1);
                longest = max(longest , m[temp]+1);
            }    
            m[nums[i]] = longest;
            ans = max(ans,longest);
        }

        return ans;
    }
};