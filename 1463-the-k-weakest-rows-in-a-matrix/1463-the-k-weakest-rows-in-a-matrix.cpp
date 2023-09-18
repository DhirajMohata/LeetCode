class Solution {
public:
    bool cmpp(vector<int> a , vector<int> b)
    {
        int x=0,y=0;
        for(int i=0; i<a.size()-1; i++)
        {
            if(a[i]==1)
                x++;
            if(b[i]==1)
                y++;
        }
        return x<=y;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        for(int i=0; i<mat.size(); i++)
        {
            mat[i].push_back(i);
        }

        sort(mat.begin() , mat.end() );

        vector<int> ans;

        for(int i=0; i<k; i++)
            ans.push_back(mat[i][mat[i].size()-1]);

        return ans;
    }
};