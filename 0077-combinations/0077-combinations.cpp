class Solution {
public:
    void sub(vector<int>& v,vector<vector<int>>& ans , int i , int n ,int k,vector<int>& temp)
    {
        if(i==n)
        {
            if(k == temp.size())
            {
                ans.push_back(temp);
            }
            return;
        }
        
        temp.push_back(v[i]);
        sub(v,ans , i+1 , n , k , temp);
        temp.pop_back();
        sub(v,ans , i+1 , n , k , temp);
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> temp1;

        for(int i=0; i<n; i++)
        {
            temp.push_back(i+1);
        }

        sub(temp , ans , 0 , n , k , temp1);
        return ans;
    }
};