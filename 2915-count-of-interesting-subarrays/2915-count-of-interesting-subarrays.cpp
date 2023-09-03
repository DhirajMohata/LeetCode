class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) 
    {
        vector<int> v(nums.size(),0);
        unordered_map<int,int> m;
        long long ans=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]%mod==k)
            {
                if(i!=0)
                    v[i] = v[i] + v[i-1];
                v[i]++;
            }
            else
            {
                if(i!=0)
                    v[i] = v[i] + v[i-1];
            }
            
            if(v[i]%mod==k)
                ans++;
            
            ans += m[(v[i]-k)%mod];
            
            m[v[i]%mod]++;
        }

        return ans;
    }
};