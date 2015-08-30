class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        
        int dp[m][n];//dp[i][j] means the minimum hp from [i][j] to [m-1][n-1]
        
        dp[m-1][n-1]=max(0-dungeon[m-1][n-1],0);
        
        //initial the bottom line
        for(int i=n-2; i>=0; i--){
            //from right to left
            dp[m-1][i]=max(dp[m-1][i+1]-dungeon[m-1][i],0);
        }
        
        //initial the rightmost column
        for(int i=m-2; i>=0; i--){
            dp[i][n-1]=max(dp[i+1][n-1]-dungeon[i][n-1],0);
        }
        
        //fill from right to left from down to up
        for(int i=m-2; i>=0; i--){
            for(int j=n-2;j>=0; j--){
                dp[i][j]=max(min(dp[i+1][j],dp[i][j+1])-dungeon[i][j],0);
            }
        }
        
        return dp[0][0]+1;
    }
};