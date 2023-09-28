class Solution {
public:
    int evalRPN(vector<string>& nums) 
    {
        stack<int> s;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]=="+")
            {
                int x = s.top();
                s.pop();
                int y = x + s.top();
                s.pop();
                s.push(y);
            }
            else if(nums[i]=="-")
            {
                int x = s.top();
                s.pop();
                int y = s.top()-x;
                s.pop();
                s.push(y);
            }
            else if(nums[i]=="*")
            {
                int x = s.top();
                s.pop();
                int y = x * s.top();
                s.pop();
                s.push(y);
            }
            else if(nums[i]=="/")
            {
                int x = s.top();
                s.pop();
                int y = s.top()/x;
                s.pop();
                s.push(y);
            }
            else
            {
                s.push(stoi(nums[i]));
            }
            cout << s.top() << " ";
        }    

        return s.top();
    }
};