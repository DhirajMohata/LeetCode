class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());

        long long sum = nums[0] , i = 0 , j = 1 , ans = 1;

        while(j<nums.size())
        {
            while(i<j)
            {
                long long x = (j-i)*nums[j] - sum;
                if(x>k)
                {
                    sum -= nums[i];
                    i++;   
                }
                else
                {
                    ans = max(ans , j-i+1);
                    break;
                }
            }
            sum += nums[j];
            j++;
        }

        return (int)ans;   
    }
};