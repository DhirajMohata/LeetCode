class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) 
    {
        int i=0 , j = nums.size()-1 , ans = 0;
        sort(nums.begin(),nums.end());

        while(i<=j)
        {
            if(nums[i]+nums[j]>limit)
                j--;
            else
            {
                i++;
                j--;
            }
            ans++;
        }
        return ans;
    }
};