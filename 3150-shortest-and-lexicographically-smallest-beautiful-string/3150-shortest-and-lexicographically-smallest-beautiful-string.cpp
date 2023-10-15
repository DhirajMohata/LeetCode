class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) 
    {
        int i = 0;
        
        while(i<s.size() && s[i]=='0')
            i++;
        
        int x = k;
        
        string temp = "";
        string ans = "";
        
        while(i<s.size() && x!=0)
        {
            if(s[i]=='1')
                x--;
            temp += s[i];
            i++;
        }
        
        if(x!=0)
            return "";

        ans = temp;
        
        
        for(int j=i; j<s.size(); j++)
        {
            if(s[j]=='1')
            {
                int g = 0;
                temp.erase(temp.begin());
                
                while(temp.size()!=0 && temp[0]=='0')
                {
                    temp.erase(temp.begin());
                }
                
                temp += s[j];
                
                if(temp.size() == ans.size())
                {
                    for(int l=0; l<temp.size(); l++)
                    {
                        if(ans[l]!='0' && temp[l]=='0')
                        {
                            ans = temp;
                            break;
                        }
                        if(ans[l]=='0' && temp[l] !='0')
                            break;
                    }
                }
                else if(temp.size()<ans.size())
                    ans = temp;
            }
            else
            {
                temp += '0';
            }
        }
        return ans;
    }
};