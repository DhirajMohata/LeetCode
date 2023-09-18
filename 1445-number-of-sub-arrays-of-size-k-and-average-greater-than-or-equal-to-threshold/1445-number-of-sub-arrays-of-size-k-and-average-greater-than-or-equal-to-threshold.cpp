class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) 
    {
        int ans = 0;
        int x = 0;

        for(int i=0; i<k; i++)
        {
            x+=arr[i];
        }    
        if((float)(x/k)>=(float)t)
            ans++;

        for(int i=k; i<arr.size(); i++)
        {
            x+=arr[i];
            x-=arr[i-k];

            if((float)(x/k)>=(float)t)
                ans++;
        }
        return ans;
    }
};