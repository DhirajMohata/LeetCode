class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int index, int value) 
    {
        set<pair<int,int>> s;
        
        for(int i=index; i<nums.size(); i++)
        {
            s.insert({nums[i-index],i-index});
            auto it =  s.begin();
            auto it1 = s.end();
            it1--;
            
            pair<int,int> x = *it, y=*it1;
            
            if(abs(x.first-nums[i])>=value)
            {
                cout << endl;
                return {x.second , i};
            }

            if(abs(y.first-nums[i])>=value)
            {
                cout << endl;
                return {y.second , i};
            }
        }
        return {-1,-1};
    }
};