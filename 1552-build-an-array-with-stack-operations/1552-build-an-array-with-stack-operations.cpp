class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        int x = 1;
        int i = 0;
        vector<string> ans;
        while(i<target.size() && x<=n)
        {
            ans.push_back("Push");
            if(x == target[i])
            {
                i++;
                
            }
            else
                ans.push_back("Pop");
            x++;
        }    

        return ans;
    }
};