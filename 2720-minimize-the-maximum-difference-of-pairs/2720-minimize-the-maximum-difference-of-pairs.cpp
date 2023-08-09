class Solution {
public:
    bool isPossible(int mid , vector<int> nums , int p)
    {
        int x = 0;

        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i+1]-nums[i]<=mid)
            {
                x++;
                i++;
            }
        }

        if(x>=p)
            return true;
        else
            return false;
    }

    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin() , nums.end());
        int n = nums.size(); 
        int i=0 , j=nums[n-1]-nums[0];
        int ans = 0;
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            if(isPossible(mid,nums,p))
            {
                ans = mid;
                j = mid-1;
            }
            else
            {
                i = mid+1;
            }
        }    

        return ans; 
    }
};