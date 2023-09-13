class Solution {
public:
    int integerBreak(int n) {
        int dp[n][n+1];
		for(int i=1;i<n;i++)
        {
			for(int j=0;j<=n;j++)
            {
                if(i==1)
                    dp[1][j]=1;
                else
                {
                    dp[i][j]=dp[i-1][j];
                    if(j>=i) 
                        dp[i][j]=max(dp[i][j],i*dp[i][j-i]);
                }
			}
		}

        cout<<"      ";
        for(int j2=0;j2<=n;j2++)
            cout<<j2<<" ";
        cout<<endl;
        for(int i2=1;i2<n;i2++)
        {
            int fl=1;
            for(int j2=0;j2<=n;j2++)
            {
                if(fl)
                {
                    cout<<i2<<" --> ";
                    fl=0;
                }
                cout<<dp[i2][j2]<<" ";
            }
            cout<<endl;
        }


		return dp[n-1][n];
    }
};