class Solution {
public:
    long long maximumSum(vector<int>& nums) 
    {
        unordered_map<long long,int> m;
        
        vector<vector<long long>> v;
        
        long long x = 1;

        long long y = 1 , ans=0;
        
        vector<long long> temp;

        for(int i=0; i<nums.size(); i++)
        {
            long long u = nums[i];
            ans = max(ans,u);
        }
        
        while(true)
        {
            y = x*x;
            
            if(y<=nums.size())
            {
                m[y]=1;
                temp.push_back(y);
            }
            else
                break;
            
            x++;    
        }
        
        if(temp.size()>=2)
            v.push_back(temp);
        else
            return ans;
        
        x = 2;
        
        while(true)
        {
            cout << m[x] << " " << x << "   ";
            if(m[x]==0)
            {
                vector<long long> te;
                for(int i=0; i<v[0].size(); i++)
                {
                    y = v[0][i]*x;

                    if(y<=nums.size())
                    {
                        m[y]=1;
                        te.push_back(y);
                        cout << y << " e  ";
                    }
                    else
                        break;
                }
                
                if(te.size()<2)
                {
                    cout << te.size() << " f  ";
                    break;
                }

                v.push_back(te);
            }
            x++;
        }

        cout << v.size() << " ";
    
        
        for(int k=0; k<v.size(); k++)
        {
            y = 0;
            
            for(int j=0; j<v[k].size(); j++)
            {
                y = y + nums[v[k][j]-1];
            }
            cout << y << " ";
            ans = max(ans,y);
        }

        
    
        return ans;
    }
};