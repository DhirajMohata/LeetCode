class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int i=0 , j=0;

        while(j<t.size())
        {
            if(t[j]==s[i])
                i++;
            j++;

            if(i==s.size())
                return true;
        } 
        if(i==s.size())
            return true;

        return false;
    }
};