class Solution {
public:
    int numSquares(int n) {
        if (n == 0) return 0;
        // dp[i] means the res of i
        // dp[i]= min(dp[i-j*j]+1) (2=<j<sqrt(i))
        
        vector<int> dp(n+1, 0);

        for (int i=1; i<=n; ++i) {
            //set the initial as i 1 square as max value
            dp[i] = i;
            for (int j = 2; j<=sqrt(i); ++j) {
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            }
        }

        return dp[n];
    }
};