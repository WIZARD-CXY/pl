class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        int m=grid.size();
        if(m==0){
            return 0;
        }
        
        int n=grid[0].size();
        
        if(n==0){
            return 0;
        }
        
        //dp[j] means min sum from grid[0][0] to grid[i][j]
        vector<int> dp(n,0);
        dp[0]=grid[0][0];
        
        // intial the first row
        for(int j=1; j<n; j++){
            dp[j]=grid[0][j]+dp[j-1];
        }
        
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(j==0){
                   dp[j]=grid[i][j]+dp[j];
                   continue;
                }
                dp[j]=min(dp[j],dp[j-1])+grid[i][j];
            }
        }
        
        return dp[n-1];
    }
};

