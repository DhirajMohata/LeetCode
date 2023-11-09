class Solution {
public:
    int getWinner(vector<int>& arr, int k) 
    {
        unordered_map<int,int> m;
        int x = 0;
        int prev = arr[0];
        int maxi = 0;
        
        
        for(int i=0; i<arr.size()-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                m[arr[i]]++;
                if(prev == arr[i])
                {
                    x++;
                }
                else
                {
                    x = 1;
                    prev = arr[i];
                }

                if(x==k)
                    return  arr[i];

                swap(arr[i] , arr[i+1]);
            }
            else
            {
                m[arr[i+1]]++;
                if(prev == arr[i+1])
                {
                    x++;
                }
                else
                {
                    x = 1;
                    prev = arr[i+1];
                }

                if(x==k)
                    return arr[i+1];
            }
            if(i == arr.size()-2)
            {
                m[arr.size()-1]++;
            }
        }
        
        int ans = 0;
        int y = 0;
        for(auto [key,val] : m)
        {
            if(val > y)
            {
                ans = key;
                y = val;
            }
        }

        if(y <= k)
        {
            for(int i=0; i<arr.size(); i++)
            {
                maxi = max(maxi , arr[i]);
            }
            return maxi;
        }
        return ans;
    }
};