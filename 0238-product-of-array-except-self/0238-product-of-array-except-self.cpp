class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int zeroes = 0 , product=nums[0] , j=1;

        if(nums[0]==0)
        {
            product=nums[1];
            zeroes++;
            j=2;
        }

        for(int i=j; i<nums.size(); i++)
        {
            if(nums[i]==0)
            {
                zeroes++;
            }
            else{
                product*=nums[i];
            }
        }

        if(zeroes>=2)
        {
            vector<int> x(nums.size(),0);
            return x;
        }
        vector<int> ans;

        if(zeroes==1)
        {
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i]==0)
                {
                    ans.push_back(product);
                }
                else{
                    ans.push_back(0);
                }
            }
        }
        else{
            for(int i=0; i<nums.size(); i++)
            {
                ans.push_back(product/nums[i]);
            }
        }

        return ans;
    }
};