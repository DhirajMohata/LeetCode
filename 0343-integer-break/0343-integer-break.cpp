class Solution {
public:
    int integerBreak(int n) 
    {
        int maxi = 0;

        for(int i=2; i<=n; i++)
        {
            int x = n/i , temp = 1;
            int y = n%i;

            temp = pow(x+1 , y)*pow(x , i-y);
            maxi = max(maxi , temp);;
        }    

        return maxi;
    }
};