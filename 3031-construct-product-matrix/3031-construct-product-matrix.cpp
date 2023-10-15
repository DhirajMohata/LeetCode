class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& nums) 
    {
        long long x = 1;
        vector<vector<int>> pre = nums , post = nums;
        
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<nums[i].size(); j++)
            {
                pre[i][j] = (int)x;
                x = (x*nums[i][j])%12345;
            }
        }
        pre[0][0] = 1;
        x = 1;
        
        for(int i=nums.size()-1; i>=0; i--)
        {
            for(int j=nums[i].size()-1; j>=0; j--)
            {
                post[i][j] = (int)x;
                x = (x*nums[i][j])%12345;
            }
        }
        

        post[nums.size()-1][nums[0].size()-1]=1;
        
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<nums[i].size(); j++)
            {
               nums[i][j] = (pre[i][j]*post[i][j])%12345;
            }
        }
        return nums;
    }
};