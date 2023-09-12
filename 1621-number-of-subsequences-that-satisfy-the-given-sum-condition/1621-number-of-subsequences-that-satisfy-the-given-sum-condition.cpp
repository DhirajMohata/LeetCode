class Solution {
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        int ans = 0;
        int mod = 1000000007;
        sort(nums.begin(),nums.end());

        vector<int> v(100000,1);

        for(int i=1; i<v.size(); i++)
            v[i] = (v[i-1]*2)%mod;

        int x = 0 , y = nums.size()-1;

            while(x<=y)
            {
                if(nums[x]+nums[y] <= target)
                {
                    ans = (ans+v[y-x]) % mod;
                    x++;
                }
                else
                    y--;
            }

        return ans;
    }
};