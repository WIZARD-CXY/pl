class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        int count=0;
        
        int m=grid.size();
        if(m==0){
            return count;
        }
        
        int n=grid[0].size();
        if(n==0){
            return count;
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<bool> > &grid ,int x, int y){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()){
            return;
        }
        
        if(!grid[x][y]){
            return;
        }
        
        grid[x][y]=0;
        int dx[]={0,-1,0,1};
        int dy[]={-1,0,1,0};
        
        for(int i=0; i<4; i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            dfs(grid,xx,yy);
        }
    }
};
