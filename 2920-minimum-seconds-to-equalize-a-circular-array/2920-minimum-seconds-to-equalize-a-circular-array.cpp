class Solution {
public:   
    int minimumSeconds(vector<int>& nums) 
    {
        unordered_map<int,vector<int>> m;
        // finding max difference between 2 same elements like [2,1,3,3,2] max diff for 2 is 3
        for(int i=0; i<nums.size(); i++) 
        {
            if(m[nums[i]].size()==0)
            {
                vector<int> x(3,-1);
                x[0]=i;
                x[1]=i;
                x[2]=0;
                m[nums[i]] = x;
            }
            else
            {
                m[nums[i]][2] = max(m[nums[i]][2],i-m[nums[i]][1]-1);
                m[nums[i]][1] = i;
            }
        }
        
        int x = nums.size()+1;
        int y = 0; 
        int size = nums.size()-1;

        //this loop is to find a diffrece for elements between first and last of same element
        // like for [2,1,3,3,2] elements are 0 for 2 and for 3 elements are 3
        // by acessing all the keys of map
        for(auto [key,val] : m)
        {
            if(m[key][1]!=m[key][0])
                m[key][2] = max(m[key][2] , size-m[key][1]+m[key][0]);
            else
                m[key][2] = nums.size()-1;
            
            if(m[key][2]<x)
            {
                x = m[key][2];
                y = m[key][2];
            } 
        }
        
        // as the both elements will reduse 1 thats why we divided by 2
        return (y+1)/2;
    }
};