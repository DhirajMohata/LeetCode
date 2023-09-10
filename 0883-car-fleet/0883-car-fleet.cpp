class Solution {
public:
    int carFleet(int target, vector<int>& nums1, vector<int>& nums2) 
    {
        vector<pair<int,int>> v;

        for(int i=0; i<nums1.size(); i++)
        {
            v.push_back({nums1[i],nums2[i]});
        }
        
        sort(v.begin(),v.end());
        stack<float> s;

        for(int i=0; i<nums1.size(); i++)
        {
            float temp = ((float)(target-v[i].first))/((float)v[i].second);
            while(!s.empty() && s.top()<=temp)
            {
                s.pop();
            }
            s.push(temp);
        }

        return s.size();
    }
};