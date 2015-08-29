class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        
        if(m==0){
            return 0;
        }
        
        int n=dungeon[0].size();
        
        if(n==0){
            return 0;
        }
        vector<vector<int> > dp(m,vector<int>(n,0));
        //dp[i][j] means the min hp from [i][j] to [m-1][n-1]
        
        dp[m-1][n-1]=max(0,-dungeon[m-1][n-1]);
        
        //initial rightmost col
        for(int i=m-2; i>=0; i--){
            dp[i][n-1]=max(dp[i+1][n-1]-dungeon[i][n-1],0);
        }
        
        //initial bottom line
        for(int j=n-2; j>=0; j--){
            dp[m-1][j]=max(dp[m-1][j+1]-dungeon[m-1][j],0);
        }
        
        // from right to left, from down to up
        for(int i=m-2;i>=0; i--){
            for(int j=n-2; j>=0; j--){
                dp[i][j]=max(0,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);
            }
        }
        
        return dp[0][0]+1;
        
    }
};