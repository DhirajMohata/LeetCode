class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        vector<int> m(26,0);
        vector<int> c(26,0);
        vector<int> x(26,0);


        for(int i=0; i<s1.size(); i++)
            m[s1[i]-'a']++;

        int j = 0 , y = 0;

        for(int i=0; i<s2.size(); i++)
        {
            if(m[s2[i]-'a']!=x[s2[i]-'a'])
            {
                if(y==0)
                    j=i;

                x[s2[i]-'a']++;
                y++;
            }
            else
            {
                if(x==m)
                    return true;

                if(m[s2[i]-'a']==0 || y==0)
                {
                    x=c;
                    y=0;
                }
                else
                {
                    while(j<=i)
                    {
                        if(s2[i]==s2[j])
                        {
                            j++;
                            break;
                        }
                        x[s2[j]-'a']--;
                        j++;
                    }
                }
            }
        }

        if(x==m)
            return true;

        return false;
    }
};