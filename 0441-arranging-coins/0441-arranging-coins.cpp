class Solution {
public:
    int arrangeCoins(int n) 
    {
        int i = 1 , j = n;

        while(i<=j)
        {
            long long mid = i + (j-i)/2;

            long long x = mid*(mid+1)/2;

            if(x<=n)
            {
                i = mid+1;
            }
            else
            {
                j = mid - 1;
            }
        }

        return j;
    }
};