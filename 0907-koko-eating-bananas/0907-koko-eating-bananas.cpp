class Solution {
public:
    bool isPossible(int mid , vector<int> arr , int H)
    {
        long long ans = 0;
        long long h = H;

        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]%mid==0)
            {
                ans += arr[i]/mid;
            }
            else{
                ans += arr[i]/mid + 1;
            }
        }

        if(ans<=h)
        {
            return true;
        }
        else{
            return false;
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int ans = 0 , i=1 , j = 1e9+5; 

        while(i<=j)
        {
            int mid = i + (j-i)/2;

            if(isPossible(mid , piles , h))
            {
                j = mid-1;
                ans = mid;
            }
            else
            {
                i = mid+1;
            }
        }

        return ans;
    }
};