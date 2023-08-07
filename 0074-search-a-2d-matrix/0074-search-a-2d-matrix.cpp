class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int t) 
    {
        int n = arr.size() , m = arr[0].size();
        for(int i=0; i<n; i++)
        {
            if(arr[i][m-1]==t)
                return true;
            else if (arr[i][m-1]>t)
            {
                int k=0,j=m-1;
                int mid;
                while(k<=j)
                {
                    mid = k + (j-k)/2;

                    if(arr[i][mid]==t)
                        return true;
                    else if(arr[i][mid]>t)
                        j = mid-1;
                    else
                        k = mid + 1;
                }
                return false;
            }
        }
        return false;
    }
};