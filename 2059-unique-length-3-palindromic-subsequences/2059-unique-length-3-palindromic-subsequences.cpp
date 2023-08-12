class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        int ans = 0;
        
        vector<vector<int>> arr(26,vector<int> (2,-1));

        for(int i=0; i<s.length(); i++)
        {
            if(arr[s[i] - 'a'][0] == -1) arr[s[i] - 'a'][0] = i;
            else arr[s[i] - 'a'][1] = i; 
        }

        for(int i=0; i<26; i++)
        {
            int freq[26] = {0};

            for(int k = arr[i][0]+1; k<arr[i][1]; k++)
            {
            if(freq[s[k] - 'a'] == 0) ans++;
            freq[s[k] - 'a'] = 1;      
            }
            
        }

        return ans;
    }
};