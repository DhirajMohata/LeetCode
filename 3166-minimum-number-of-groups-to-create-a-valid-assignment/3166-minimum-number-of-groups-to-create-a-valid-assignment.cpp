class Solution {
public:
    int ispossible(int x , vector<int>& temp)
    {
        int flag = 0 , flag1 = 0;
        
        int ans = 0;
        
        for(int i=0; i<temp.size(); i++)
        {
            int y = temp[i]/x , z = temp[i]%x;
            
            if(z<=y)
                ans += y;
            
            else
            {
                flag = 1;
                break;
            }
        }
        
        if(flag == 1)
        {
            ans = 0;
            for(int i=0; i<temp.size(); i++)
            {
                int y = temp[i]/x , z = temp[i]%x;
                
                if(z == 0)
                    ans += y;
                else if( x - z <= y + 1 || z == x-1)
                    ans += y + 1;

                else
                {
                    flag1 = 1;
                    break;
                }
            }
        }
        
        if(flag == 1 && flag1 == 1)
        {
            cout << x;
            return -1;
        }
        return ans;
    }
    
    int minGroupsForValidAssignment(vector<int>& nums) 
    {
        unordered_map<int,int> m;
        
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }
        
        int mini = INT_MAX;
        vector<int> temp;
        
        for(auto [key,val] : m)
        {
            mini = min(mini , val);
            temp.push_back(val);
        }
    
        for(int i=mini+1; i>= 1; i--)
        {
            int te = ispossible(i , temp);

            if(te != -1)
            {
                return te;
            }
        }
        
        return -1;
    }
};