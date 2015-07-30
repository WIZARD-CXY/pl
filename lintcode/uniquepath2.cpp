class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int m=obstacleGrid.size();
        if(m==0){
            return 0;
        }
        
        int n=obstacleGrid[0].size();
        if(n==0){
            return 0;
        }
        
        vector<int> dp(n,0);
        
        dp[0]=obstacleGrid[0][0]==1?0:1;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]){
                    dp[j]=0;
                    continue;
                }
                
                if(j!=0){
                    dp[j]=dp[j]+dp[j-1];
                }
            }
        }
        
        return dp[n-1];
    }
};
