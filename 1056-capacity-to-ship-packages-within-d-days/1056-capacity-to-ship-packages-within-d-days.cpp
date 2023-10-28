class Solution {
public:
    bool ispossible(vector<int>& nums , int x , int days)
    {
        int temp = 0;
        days--;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>x)
                return false;

            if(temp + nums[i] <= x)
            {
                temp += nums[i];
            }
            else
            {
                if(days == 0)
                    return false;
                days--;
                temp = nums[i];
            }
        }

        return true;
    }

    int shipWithinDays(vector<int>& nums, int days) 
    {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
            sum += nums[i];     

        int i = 1, j = sum , ans = 0;

        while(i <= j)
        {
            int mid = i + (j-i)/2;

            if(ispossible(nums , mid , days))
            {
                ans = mid;
                j = mid - 1;
            }
            else
            {
                i = mid + 1; 
            }
        }

        return ans;
    }
};