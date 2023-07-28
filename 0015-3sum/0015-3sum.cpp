class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        set<vector<int>> ans;
        vector<int> temp;
        int i=0 , j=nums.size()-1 , sum = 0;
        sort(nums.begin(),nums.end());

        for(int k=0; k<nums.size(); k++)
        {
            i=k+1;
            j=nums.size()-1;
            sum = nums[k]*(-1);
            
            //Two pointer
            while(i<j)
            {
                if(nums[i]+nums[j]==sum)
                {
                    temp.push_back(nums[k]);
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    ans.insert(temp);
                    temp.clear();
                    i++;
                    j--;
                }
                else if(nums[i]+nums[j]>sum)
                    j--;
                else
                    i++;
            }
        }

        vector<vector<int>> s;
        for(auto it : ans)
        {
            s.push_back(it);
        }
        return s;
    }
};