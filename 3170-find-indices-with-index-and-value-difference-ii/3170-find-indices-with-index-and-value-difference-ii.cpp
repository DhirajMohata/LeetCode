class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int index, int value) 
    {
        int maxi = nums[0] , mini = nums[0] , x = 0 , y = 0;
        
        for(int i=index; i<nums.size(); i++)
        {
            if(nums[i-index]>maxi)
            {
                maxi = nums[i-index];
                x = i-index;
            }

            if(nums[i-index]<mini)
            {
                mini = nums[i-index];
                y = i-index;
            }
            
            if(abs(maxi-nums[i])>=value)
                return {x , i};

            if(abs(mini-nums[i])>=value)
            {
                return {y , i};
            }
        }
        return {-1,-1};
    }
};