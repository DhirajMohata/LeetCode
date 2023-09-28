class Solution {
public:
    string removeStars(string s) 
    {
        stack<char> a;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='*')
                a.pop();
            else
                a.push(s[i]);
        }
        string ans = "";

        while(!a.empty())
        {
            ans += a.top();
            a.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};