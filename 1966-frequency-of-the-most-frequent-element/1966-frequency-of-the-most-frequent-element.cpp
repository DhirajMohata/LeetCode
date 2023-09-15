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
                if(x<=k)
                {
                    ans = max(ans , j-i+1);
                    cout << ans << " ";
                    break;
                }
                else
                {
                    sum -= nums[i];
                    i++;
                }
            }
            sum += nums[j];
            j++;
        }

        return (int)ans;   
    }
};