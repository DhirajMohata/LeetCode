class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        int flag = 0 , flag1 = 0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]>nums[i-1])
                flag = 1;
        }

        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]>nums[i+1])
                flag1 = 1;
        }

        if(flag == 0 || flag1 == 0)
        {
            return true;
        }
        return false;
    }
};