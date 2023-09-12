class Solution {
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        long long ans = 0;
        long long mod = 1000000007;
        sort(nums.begin(),nums.end());

        vector<long long> v(100000,1);

        for(int i=1; i<v.size(); i++)
            v[i] = (v[i-1]*2)%mod;

        for(int i=0; i<nums.size(); i++)
        {
            int x = i , y = nums.size()-1 , d=i;

            if(nums[i]+nums[i]>target)
                break;

            while(x<=y)
            {
                int mid = x + (y-x)/2;
                if(nums[mid]+nums[i] <= target)
                {
                    x = mid+1;
                    d = mid;
                }
                else
                    y = mid-1;
            }
            
            int z = d-i;

            ans = (ans+v[z]) % mod;
        
        }
        int a = (int)ans;
        return a;
    }
};