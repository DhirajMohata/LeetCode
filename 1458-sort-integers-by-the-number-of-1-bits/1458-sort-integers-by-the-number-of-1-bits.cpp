class Solution {
public:
    static bool cmp(int x , int y)
    {
        int a = __builtin_popcount(x);
        int b = __builtin_popcount(y);

        if(a==b)
            return x < y;
        return a < b;
    }
    vector<int> sortByBits(vector<int>& arr) 
    {
        sort(arr.begin() , arr.end() , cmp);    
        return arr;
    }
};