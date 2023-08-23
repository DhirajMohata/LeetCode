class Solution {
public:
    string reorganizeString(string s) 
    {
        vector<int> v(26,0);
        string ans = "";

        for(int i=0; i<s.length(); i++)
        {
            v[s[i]-'a']++;
            if(v[s[i]-'a']>(s.length()+1)/2)
                return ans;
        }

        stack<char> x;
        ans = ans + s[0];
        int j=1;

        while(j!=s.length())
        {
            if(ans[ans.length()-1]==s[j])
            {
                x.push(s[j]);
            }
            else
            {
                ans += s[j];
                if(!x.empty())
                {
                    ans += x.top();
                    x.pop();
                }
            }
            j++;
        }

        while(!x.empty())
        {
            if(ans[0]!=x.top())
            {
                cout << ans << " ";
                string te = "";
                te += x.top();
                ans.insert(0 , te);
                cout << ans << " ";
                x.pop();
            }
            else if(ans[ans.length()-1]!=x.top())
            {
                ans += x.top();
                x.pop();
            }
            else
            {
                for(int i=1; i<ans.length()-1; i++)
                {
                    if(ans[i-1]!=x.top() && ans[i]!=x.top())
                    {
                        string te = "";
                        te += x.top();
                        ans.insert(i , te);
                        x.pop();
                        break;
                    }
                }
            }
        }

        return ans;
    }
};