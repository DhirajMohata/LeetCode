class Solution {
public:
    int minOperations(vector<int>& nu) 
    {
        sort(nu.begin(),nu.end());

        vector<int> nums;
        nums.push_back(nu[0]);
        
        for(int i=1; i<nu.size(); i++)
        {
            if(nu[i-1]==nu[i])
                continue;
            else
            {
                cout << nu[i] << " ";
                nums.push_back(nu[i]);
            }
        }

        int ans = 0 , i , j;

        for(int k=0; k<nums.size(); k++)
        {
            i = k ;
            j = nums.size()-1;

            while(i<=j)
            {
                int mid = i + (j-i)/2;

                if( nums[mid] - nums[k] <= nu.size()-1)
                {
                    i = mid + 1;
                }
                else
                {
                    j = mid - 1;
                }
            }

            ans = max(ans , j-k+1);
        }

        return nu.size() - ans;
    }
};