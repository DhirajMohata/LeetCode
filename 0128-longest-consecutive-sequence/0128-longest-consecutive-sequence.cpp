class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int i=0,ans=0,y=0,prev;
        for(int i=0; i<nums.size(); i++)
        {
            s.insert(nums[i]);
        }

        for(auto it: s)
        {
            if(i!=0)
            {
                if(it==prev+1)
                {
                    y++;
                }
                else{
                    ans = max(y+1,ans);
                    y=0;
                }
            }
            prev=it;
            i++;
        }
        ans = max(y+1,ans);
        if(nums.size()==0)
        {
            return 0;
        }
        return ans;
    }
};