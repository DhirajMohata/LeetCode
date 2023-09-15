class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());

        long long sum = 0 , i = 0 , j = 0 , ans = 1;

        while(j<nums.size())
        {
            sum += nums[j];
            while((j-i+1)*nums[j] - sum > k)
            {
                sum -= nums[i];
                i++;
            }
            ans = max(ans , j-i+1);
            j++;
        }

        return (int)ans;   
    }
};