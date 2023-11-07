class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        vector<double> v(dist.size());

        for(int i=0; i<dist.size(); i++)
        {
            v[i] = (double)dist[i]/speed[i];
        }

        sort(v.begin(),v.end());
        int x = 1 , ans = 1;

        for(int i=0; i<v.size(); i++)
        {
            if(v[i] <= i)
            {
                return i;
            }
        }

        return v.size();
    }
};