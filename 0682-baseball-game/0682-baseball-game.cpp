class Solution {
public:
    int calPoints(vector<string>& S) 
    {
        stack<int> s;

        for(int i=0; i<S.size(); i++)
        {
            if(S[i]=="C")
            {
                s.pop();
            }
            else if(S[i]=="D")
            {
                int x = s.top();
                s.push(2*x);
            }
            else if(S[i]=="+")
            {
                int x = s.top();
                s.pop();
                int y = x + s.top();
                s.push(x);
                s.push(y);
            }
            else
            {
                s.push(stoi(S[i]));
            }
        }  

        int ans = 0;
        
        while(!s.empty())
        {
            ans += s.top();
            cout << s.top() << " ";
            s.pop();
        }

        return ans;
    }
};