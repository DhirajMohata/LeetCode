class Solution {
public:
    int solve(vector<int>& nums , int x)
    {
        unordered_map<long long,int> m;
        long long sum = 0;
        int ans = -1;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            
            if(m[sum-x]>=1)
            {
                ans = max(ans , i - m[sum-x]+1);
            }
            if(sum == x)
                ans = max(ans , i + 1);
            
            m[sum] = i+1;
        }
        
        return ans;
    }
    
    int solve1(vector<int>& nums , int x)
    {
        unordered_map<long long,int> m;
        long long sum = 0;
        int ans = INT_MAX;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            
            if(m[sum-x]>=1)
            {
                ans = min(ans , i - m[sum-x]+1);
                
            }
            if(sum == x)
                ans = min(ans , i + 1);
            
            m[sum] = i+1;
        }
        
        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }
    
    int minSizeSubarray(vector<int>& nums, int tar) 
    {
        long long sum = 0;
        
        for(int i=0; i<nums.size(); i++)
            sum += nums[i];
        
        long long x = tar%sum;
        cout << x << " ";
        
        long long y = sum - x;
        
        
        int ans = solve(nums,y);
        int ans1 = solve1(nums,x);
        
        int c = ans1 + (tar/sum)*nums.size();
        if(ans == -1)
        {
            if(ans1==-1)
                return -1;

            return c;
        }
        
        int z = nums.size() - ans;
        
        int b = z + (tar/sum)*nums.size();
       
        if(ans1 != -1)
            return min(c,b);
        
        return b;
        
    }
};