class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //use dp
        int n=triangle.size();
        //dp[i][j] means starting from the i,j the minimum value we can get
        vector<int> dp(n,0);
        //dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])
        
        //fill the bottom line
        for(int i=0; i<n; i++){
            dp[i]=triangle[n-1][i];
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
            }
        }
        
        return dp[0];
    }
};