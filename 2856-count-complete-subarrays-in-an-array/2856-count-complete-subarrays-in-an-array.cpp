class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> m;
        vector<int> req;
        int n=nums.size(),ans=0,x;
        set<int> temp;
        
        for(int i=0; i<nums.size(); i++)
        {
            m.insert(nums[i]);
        }
        x=m.size();
        for(int i = 0; i < n; i++)  
        {
            for(int j = i; j<n; j++)  
            {  
                temp.insert(nums[j]);
                if(temp.size()==x)
                {
                    ans+=n-j;
                    break;
                }
            } 
            temp.clear();
        }  
        return ans;
    }
};