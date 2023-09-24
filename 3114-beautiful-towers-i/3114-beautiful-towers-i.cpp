class Solution {
public:
    long long maximumSumOfHeights(vector<int>& nums) 
    {
        long long ans = 0;
        vector<int> temp = nums;
        
        for(int i=0; i<nums.size(); i++)
        {
            int x = i-1 , y = i+1 , maxi = nums[i], mini = nums[i];
            
            long long sum = 0;
            
            while(x>=0 || y<nums.size())
            {
                if(x>=0)
                {
                    if(nums[x]>maxi)
                    {
                        nums[x] = maxi;
                    }
                    else
                    {
                        maxi = nums[x];
                    }              
                }

                if(y<nums.size())
                {
                    if(nums[y] > mini)
                    {
                        nums[y] = mini;
                    }
                    else
                    {
                        mini = nums[y];
                    }
                }
                
                x--;
                y++;
            }
            
            for(int k=0; k<nums.size(); k++)
            {
                sum += nums[k];
            }
            
            ans = max(ans , sum);
            nums = temp;
        }
        
        return ans;
    }
};