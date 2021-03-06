class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();

        //we modify the grid here ,grid[i][j] means from [0][0] to [i][j] the smallest value we can get
        // the first row can only be updated from left to right
        for(int i=1; i<col; i++){
            grid[0][i]=grid[0][i-1]+grid[0][i];
        }
        
        //the first col can only be updated from up to down
        for(int i=1; i<row; i++){
            grid[i][0]=grid[i-1][0]+grid[i][0];
        }
        
        for(int i=1; i<row; i++){
            for(int j=1; j<col;j++){
                grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j];
            }
            
        }
        
        return grid[row-1][col-1];
        
    }
};