class Solution {
public:
    int trap(vector<int>& nums) 
    {
        int i=0 , j = i+1 , ans = 0;
        stack<int> v;

        while(j<nums.size())
        {
            if(nums[j]>=nums[i])
            {
                int temp = nums[i]*(j-i-1); 
                while(!v.empty())
                {
                    temp -= v.top();
                    v.pop();
                }

                i=j;
                j++;
                ans += temp;
            }
            else
            {
                v.push(nums[j]);
                j++;
            }
        }    

        while(!v.empty())
            v.pop();

        i = nums.size()-1;
        j = i-1;

        while(j!=-1)
        {
            if(nums[j]>nums[i])
            {
                int temp = nums[i]*(i-j-1); 
                while(!v.empty())
                {
                    temp -= v.top();
                    v.pop();
                }

                i=j;
                j--;
                ans += temp;
            }
            else
            {
                v.push(nums[j]);
                j--;
            }
        }
        
        return ans;
    }
};