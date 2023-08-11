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
        int ans = piles[0];

        for(int i=0; i<piles.size(); i++)
        {
            ans = max(ans , piles[i]);
        }

        int i=1 , j = ans; 

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