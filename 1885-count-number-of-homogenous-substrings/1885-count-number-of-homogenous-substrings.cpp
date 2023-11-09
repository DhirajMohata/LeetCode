class Solution {
public:
    int countHomogenous(string s) 
    {
        int mod = 1000000007;

        long long ans = 0;
        int i = 0;
        

        while(i<s.size())
        {
            char temp = s[i];
            long long x = 0;
            while(s[i] == temp)
            {
                x++;
                i++;
            }

            ans = (ans + (x*(x+1)/2) ) % mod;
        }    
        int a = (int)ans%mod; 
        return ans;
    }
};