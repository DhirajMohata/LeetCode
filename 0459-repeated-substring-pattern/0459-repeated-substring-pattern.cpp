class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        int n = s.length();

        for (int i = 1; i <= n / 2; ++i) 
        {
            if (n % i == 0) 
            {
                string temp = s.substr(0, i);
                string r = "";

                for (int j = 0; j < n / i; j++) 
                {
                    r += temp;
                }

                if (r == s) 
                    return true;
            }
        }

        return false;
    }
};