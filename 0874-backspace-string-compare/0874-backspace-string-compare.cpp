class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        string x = "" , y = "";

        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='#')
            {
                if(x.size()!=0)
                {
                    x.pop_back();
                }
            }
            else
            {
                x += s[i];
            }
        }   

        for(int i=0; i<t.size(); i++)
        {
            if(t[i]=='#')
            {
                if(y.size()!=0)
                {
                    y.pop_back();
                }
            }
            else
            {
                y += t[i];
            }
        }    

        if(x == y)
            return true;
        
        return false;
    }
};