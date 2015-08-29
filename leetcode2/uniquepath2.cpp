class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        if(m==0){
            return 0;
        }
        
        int n=obstacleGrid[0].size();
        if(n==0){
            return 0;
        }
        
        vector<vector<int> > d(m,vector<int>(n,0));
        
        d[0][0]=obstacleGrid[0][0]?0:1;
        for(int i=1; i<m; i++){
            if(obstacleGrid[i][0]){
                d[i][0]=0;
            }else{
                d[i][0]=d[i-1][0];
            }
        }
        
        for(int j=1; j<n; j++){
            if(obstacleGrid[0][j]){
                d[0][j]=0;
            }else{
                d[0][j]=d[0][j-1];
            }
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]){
                    d[i][j]=0;
                }else{
                    d[i][j]=d[i-1][j]+d[i][j-1];
                }
            }
        }
        
        return d[m-1][n-1];
    }
};