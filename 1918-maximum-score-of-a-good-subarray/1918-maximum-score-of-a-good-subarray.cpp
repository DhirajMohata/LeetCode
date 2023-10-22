class Solution {
public:
    int maximumScore(std::vector<int>& nums, int k) 
    {
        int left = k, right = k;
        int mini = nums[k];
        int maxi = mini;

        while (left > 0 || right < nums.size() - 1) 
        {
            if( (left == 0 || (right < nums.size() - 1) && nums[right + 1] > nums[left - 1])) 
            {
                right++;
            } 
            else 
            {
                left--;
            }
            mini = min(mini , min(nums[left], nums[right]));
            maxi = max(maxi, mini * (right - left + 1));
        }
        
        return maxi;
    }
};