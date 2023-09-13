class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int l, int x) 
    {
        int i=0 , j=1;

        if(nums.size()==l)
            return nums;
            
        vector<int> ans;

        while(j<nums.size() && nums[j]<x)
            j++;
            
        if(j==nums.size())
        {
            for(int k=nums.size()-l; k<nums.size(); k++)
                ans.push_back(nums[k]);
            return ans;
        }

        i = j-1;

        while(l)
        {
            if((i==-1) || (j!=nums.size() && abs(nums[i]-x)>abs(nums[j]-x)))
            {
                ans.push_back(nums[j]);
                j++;
                l--;
            }
            else
            {
                ans.push_back(nums[i]);
                i--;
                l--;
            }
        }
            
        if(ans.size()!=0)
        {
            sort(ans.begin(),ans.end());
            return ans;
        }
        
        for(int m=0; m<l; m++)
            ans.push_back(nums[m]);

        return ans;
    }
};