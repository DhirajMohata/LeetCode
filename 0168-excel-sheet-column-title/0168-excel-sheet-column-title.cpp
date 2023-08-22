class Solution {
public:
    string convertToTitle(int n) 
    {
        int x = 26;
        string ans = "";
        string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        while(n)
        {
            int z = (n-1)%26;
            ans = ans + s[z];

            n = (n-1)/26;
            cout << ans << " " << n << " ";
        }    

        reverse(ans.begin(),ans.end());

        return ans; 
    }
};