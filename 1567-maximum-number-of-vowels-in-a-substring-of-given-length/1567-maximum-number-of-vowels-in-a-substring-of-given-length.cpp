class Solution {
public:
    int maxVowels(string s, int k) 
    {
        int x = 0 , ans = 0;
        unordered_map<char,int> m;

        m['a'] = 1;
        m['e'] = 1;
        m['i'] = 1;
        m['o'] = 1;
        m['u'] = 1;

        for(int i=0; i<k; i++)
        {
            if(m[s[i]]==1)
                x++;
        }
        ans = max(ans , x);
        int i=0;

        for(int j=k; j<s.size(); j++)
        {
            if(m[s[j]]==1)
                x++;
            if(m[s[i]]==1)
                x--;

            ans = max(ans,x);
            i++;
        }

        return ans;
    }
};