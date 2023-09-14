class Solution {
public:
    int numRabbits(vector<int>& nums) 
    {
        map<int,int> m;
        int ans = 0;

        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;

        for(auto [key,val] : m)
        {
            int temp = val/(key+1);

            if(val%(key+1)!=0)
              temp++;
              
            ans += temp*(key+1);
        }

        return ans;
    }
};