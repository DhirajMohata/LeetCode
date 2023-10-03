class Solution {
public:
    int maxArea(int h, int w, vector<int>& nums, vector<int>& nums1) 
    {
        sort(nums.begin() , nums.end());
        sort(nums1.begin() , nums1.end());

        int x = 0 , y = 0;

        x = max(x , nums[0] - 0);
        x = max(x , h - nums[nums.size()-1]);
        y = max(y , nums1[0] - 0);
        y = max(y , w - nums1[nums1.size()-1]);

        for(int i=0; i<nums.size()-1;i++)
        {
            x = max(x , nums[i+1] - nums[i]);
        }

        for(int i=0; i<nums1.size()-1;i++)
        {
            y = max(y , nums1[i+1] - nums1[i]);
        }

        long long ans = (long long)x*(long long)y;
        ans = ans % 1000000007;

        return (int)ans;
    }
};