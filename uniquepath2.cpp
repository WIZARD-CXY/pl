class Solution {
public:
    int f[101][101];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(f,0,sizeof(f));
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        return dfs(obstacleGrid,m,n);
    }
    
    int dfs(vector<vector<int> > &obstacleGrid, int x, int y){
        if(x<1 || y<1){
            return 0;
        }

        // met a obstacle just return 0 indicate 0 solution
        if(obstacleGrid[x-1][y-1]){
            return 0;
        }
        
        if(x==1 && y==1){
            return 1;
        }
        
        if(f[x][y]){
            return f[x][y];
        }
        
        f[x-1][y]=dfs(obstacleGrid,x-1,y);
        f[x][y-1]=dfs(obstacleGrid,x,y-1);
        
        return f[x-1][y]+f[x][y-1];
    }
};