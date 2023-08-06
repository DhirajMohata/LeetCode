class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int res=nums.size()+1,sum=0;
        int j=0;
        int i=0;
        int flag = 0;

        while(j<nums.size())
        {
            sum+=nums[j];
            while(sum>=target)
            {
                res=min(res,j-i+1);
                sum-=nums[i];
                i++;
                flag = 1;
            }
            j++;
        }

        if(flag==0)
            return 0;

        return res;
    }
};