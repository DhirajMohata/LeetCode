class Solution {
public:
    static bool cmp(string& a , string& b)
    {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& nums) 
    {
        map<string,int> m;
        int flag = 0;

        sort(nums.begin(),nums.end() , cmp);

        for(int i=0; i<nums.size(); i++)
        {
            string temp = nums[i];

            for(int j=0; j<nums[i].size(); j++)
            {
                temp.erase(j,1);
                cout << temp << " ";
                if(m[temp]>=1)
                {
                    m[nums[i]] = max(m[nums[i]] , m[temp]+1);
                    flag = 1;
                }
                temp = nums[i];

            }
            if(flag == 0)
                m[nums[i]]=1;
            else
                flag = 0;
                
            cout << endl;
        }

        int ans = 1;

        for(auto [key,val] : m)
        {
            ans = max(ans , val);
        }
        return ans;
    }
};