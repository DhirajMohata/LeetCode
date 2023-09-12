class Solution {
public:
    int maxArea(vector<int>& arr) 
    {

        int i=0,ans=0,j=arr.size()-1;
        
        while(i<j)
        {
            ans = max(ans , min(arr[i],arr[j])*(j-i)); 

            if(arr[i]<=arr[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return ans;
    }
};