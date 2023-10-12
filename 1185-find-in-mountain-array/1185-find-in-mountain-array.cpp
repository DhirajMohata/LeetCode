/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        int n = mountainArr.length();

        int x = n-1;
        int i = 1 , j = n-2;

        int ans = INT_MAX;
        
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            int c = mountainArr.get(mid);
            int v = mountainArr.get(mid+1);
            int b = mountainArr.get(mid-1);

            if(c>=v && c>=b)
            {
                x = mid;
                break;
            }

            if(c>=v)
                j = mid - 1;
            else
                i = mid + 1;
        }

        if(x == n-1)
        {
            if(mountainArr.get(0)>mountainArr.get(1) && mountainArr.get(n-1)<=mountainArr.get(n-2))
                x = 0;
            else
                x = n-1;
        }


        i = 0 , j = x;

        while(i<=j)
        {
            int mid = i + (j-i)/2;
            int c = mountainArr.get(mid);

            if(c==target)
            {
                ans = min(ans , mid);
                j = mid - 1;
            }
            else if(c>target)
            {
                j = mid-1;
            }
            else
                i = mid+1;
        }


        i = x , j = n-1;

        while(i<=j)
        {
            int mid = i + (j-i)/2;
            int c = mountainArr.get(mid);

            if(c==target)
            {
                ans = min(ans , mid);
                j = mid - 1;
            }
            else if(c>target)
            {
                i = mid+1;
            }
            else
                j = mid-1;
        }

        if(ans == INT_MAX)
            return -1;

        return ans;;
    }
};