class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        map<char,int> m;
        int ans=0,j=0;

        for(int i=0; i<s.length(); i++)
        {
           if(m.count(s[i])==0 || m[s[i]]<j)
                ans = max(ans,i-j+1);
           else
                j = m[s[i]]+1;
           
           m[s[i]] = i;
        }
        return ans;
    }
};