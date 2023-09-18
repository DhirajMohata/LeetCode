class Solution {
public:
    int totalFruit(vector<int>& nums) 
    {
        int i=0 , j=1 , x = 0 , y=1 , u = nums[0] , v = nums[0] , ans = 0;
 
        while(j<nums.size() && nums[j]==u)
            j++;

        if(j<nums.size())
        {
            v = nums[j];
            ans = max(ans,j-i+1);
        }
        else
            ans = max(ans,j-i);

        x = j-1; 
        y = j;

        j++;

        while(j<nums.size())
        {
            if(nums[j]==u || nums[j]==v)
            {
                ans = max(ans,j-i+1);

                if(nums[j]==u)
                {
                    x = j;
                }
                else
                {
                    y = j;
                }
            }
            else
            {
                if(nums[j-1]==u)
                {
                    i = y+1;
                }
                else
                {
                    i = x+1;
                    u = v;
                    x = y;
                }
                v = nums[j];
                y = j;
            }
            j++;
        }

        return ans;
    }
};