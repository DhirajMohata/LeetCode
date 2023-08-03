class Solution {
public:
    unordered_map<char,string> m;

    void letter(string s , int i , vector<string>& ans , string temp)
    {
        if(i==s.size())
        {
            ans.push_back(temp);
            return;
        }

        string x = m[s[i]];

        for(int j=0; j<x.length(); j++)
        {
            temp = temp+x[j];
            letter(s , i+1 , ans , temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        vector<string> ans;
        string temp = "";
        
        if(digits.length()==0)
            return ans;
        

        m['2']="abc";
        m['3'] ="def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        letter(digits , 0 , ans , temp);

        return ans;
    }
};