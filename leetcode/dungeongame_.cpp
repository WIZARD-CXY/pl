// this solution is using rolling array
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        
        int dp[n];
        
        dp[n-1]=max(0-dungeon[m-1][n-1],0);
        
        //initial the bottom line
        for(int i=n-2; i>=0; i--){
            //from right to left
            dp[i]=max(dp[i+1]-dungeon[m-1][i],0);
        }
        
        //fill from right to left from dowm to up
        for(int i=m-2; i>=0; i--){
            for(int j=n-1;j>=0; j--){
                if(j==n-1){
                    dp[j]=max(dp[j]-dungeon[i][j],0);
                    continue;
                }
                dp[j]=max(min(dp[j],dp[j+1])-dungeon[i][j],0);
            }
        }
        
        return dp[0]+1;
    }
};