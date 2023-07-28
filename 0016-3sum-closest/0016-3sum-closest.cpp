class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int i=0 , j=nums.size()-1 , sum = 0;
        sort(nums.begin(),nums.end());

        int ans, x = nums[nums.size()-1]+nums[nums.size()-2] + nums[nums.size()-3] , y = nums[0]+nums[1]+nums[2];

        for(int k=0; k<nums.size(); k++)
        {
            i=k+1;
            j=nums.size()-1;
            
            //Two pointer
            while(i<j)
            {
                if(nums[i]+nums[j]+nums[k] == target)
                {
                    return target;
                }
                else if(nums[i]+nums[j]+nums[k]>target)
                {
                    x = min( x , nums[i]+nums[j]+nums[k] );
                    j--;
                }
                else
                {
                    y = max( y , nums[i]+nums[j]+nums[k] );
                    i++;
                }
            }
        }


        if(abs(target-x) < abs(target-y))
        {
            return x;
        }
        return y;
        
    }
};