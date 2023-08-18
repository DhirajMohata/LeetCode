class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        map<pair<int,int>,int> m1;
        vector<int> m2(n,0);
        int ans=0;

        for(int i=0; i<roads.size(); i++)
        {
            m1[{roads[i][0],roads[i][1]}]=1;
            m2[roads[i][0]]++;
            m2[roads[i][1]]++;
        }


        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int c = m2[i]+m2[j]; 
                c-=m1[{i,j}]+m1[{j,i}];
                ans = max(ans,c);
            }
        }
        return ans;
    }
};