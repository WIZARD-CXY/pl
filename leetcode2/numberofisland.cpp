class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
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
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        
        return count;
    }
    void dfs(vector<vector<char> > & grid, int x, int y){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()){
            return;
        }
        if(grid[x][y]=='0'){
            return;
        }
        grid[x][y]='0';
        
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        
        for(int i=0; i<4; i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            dfs(grid,newx,newy);
        }
    }
};