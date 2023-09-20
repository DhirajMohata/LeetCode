class Solution {
public:
    int longestSubarrayWithSumX(vector<int>&nums,int target)
    {
        int left=0,right=0;
        int sum=0;
        int maxlen=0;
        while(right<nums.size())
        {
            sum+=nums[right];
            while(sum>target && left<=right)
            {
                sum-=nums[left];
                left++;
            }
            if(sum==target)
                maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        int target=sum-x;
        if(target==0)
            return nums.size();
        int len=longestSubarrayWithSumX(nums,target);
        if(len==0 || target<0)
            return -1;
        return nums.size()-len;
    }
};