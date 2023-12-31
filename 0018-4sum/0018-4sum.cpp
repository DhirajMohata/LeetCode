class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        long long int sum,sum2,k,l;
        long long int tar = target;
        set<vector<int>> ans;

        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                k=j+1;
                l=nums.size()-1;
                sum=nums[i]+nums[j];

                while(k<l)
                {
                    sum2=nums[k]+nums[l];
                    if(sum2+sum == tar)
                    {
                        ans.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                    else if(sum2+sum > tar)
                    {
                        l--;
                    }
                    else{
                        k++;
                    }
                }
            }
        }
        vector<vector<int>> an;
        for(auto it:ans)
        {
            an.push_back(it);
        }
        return an;
    }
};