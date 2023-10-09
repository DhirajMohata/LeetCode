class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==target)
            {
                int j = i+1;
                while(j<nums.size() && nums[j]==target)
                {
                    j++;
                }
                return {i,j-1};
            }
        }
        return {-1,-1};
    }
};