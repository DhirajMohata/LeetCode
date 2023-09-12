class Solution {
public:
    int minDeletions(string s) 
    {
        unordered_map<char,int> m;
        unordered_map<int,int> freq;
        int ans = 0;

        for(int i=0; i<s.size(); i++)
        {
            m[s[i]]++;
        }

        for(auto [key,val] : m)
        {
            freq[val]++;
        }

        for(auto [key,val] : m)
        {
            if(freq[val]>=2)
            {
                int x = val;
                while(x)
                {
                    ans++;
                    if(freq[x]==0)
                    {
                        freq[x]=1;
                        ans--;
                        break;
                    }
                    x--;
                }
                freq[val]--;
            }
        }

        return ans;
    }
};