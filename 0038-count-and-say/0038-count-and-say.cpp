class Solution {
public:
    string countAndSay(int n) 
    {
        if(n==1)
            return "1";
        string ans = "" , x = "";

        x = countAndSay(n-1);
        char temp = x[0];
        int y = 0;

        for(int i=0; i<x.size(); i++)
        {
            if(temp == x[i])
                y++;
            else
            {
                ans += to_string(y);
                ans += temp;
                temp = x[i];
                i--;
                y = 0;
            }
        }
        ans += to_string(y);
        ans += temp;

        return ans;
    }
};