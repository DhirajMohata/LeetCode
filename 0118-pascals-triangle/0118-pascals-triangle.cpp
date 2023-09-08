class Solution {
public:
    vector<vector<int>> generate(int num) 
    {
        int x = 2;
        vector<vector<int>> ans;
        ans.push_back({1});

        for(int i=1; i<num; i++)
        {
            vector<int> temp(x,1);

            for(int j=1; j<x-1; j++)
            {
                temp[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(temp);
            x++;
        }    
        return ans;
    }
};