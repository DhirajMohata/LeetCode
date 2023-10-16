class Solution {
public:
    vector<int> getRow(int row) 
    {
        vector<int> ans;

        

        for(int i=0; i<=row; i++)
        {
            ans.push_back(1);
            int x = 1;
            for(int j=1; j<i; j++)
            {
                int y = ans[j];
                ans[j] = x + ans[j];
                x = y;
            }
        }

        return ans;
    }
};