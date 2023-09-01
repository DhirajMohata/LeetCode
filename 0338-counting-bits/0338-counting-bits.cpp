class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> ans;
        int x, y = 0;

        for(int i=0; i<=n; i++)
        {
            x = i;
            y = 0;
            while(x)
            {
                if(x%2==1)
                    y++;
                x = x/2;
            }
            ans.push_back(y);
        }
        return ans;
    }
};