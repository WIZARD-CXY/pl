class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n=costs.size();
        
        if(n==0){
            return 0;
        }
        int k=costs[0].size();
        
        //dp[i][j] means color the ith house with color j the mean cost 
        vector<vector<int> > dp(n,vector<int>(k,0));
        
        for(int i=0; i<k; i++){
            dp[0][i]=costs[0][i];
        }
        
        //O(nk) time complexity
        for(int i=1; i<n; i++){
            // mincost record the pre (i-1) houses min cost
            // secondmincost record the pre (i-1) houses second min cost
            int mincost=INT_MAX;
            int secondmincost=INT_MAX;
            
            for(int j=0; j<k; j++){
                if(dp[i-1][j]<=mincost){
                    secondmincost=mincost;
                    mincost=dp[i-1][j];
                }else if(dp[i-1][j]<secondmincost){
                    secondmincost=dp[i-1][j];
                }
            }
            
            for(int j=0; j<k; j++){
                if(dp[i-1][j]==mincost){
                    dp[i][j]=costs[i][j]+secondmincost;
                }else{
                    dp[i][j]=costs[i][j]+mincost;
                }
            }
        }
        
        int res=INT_MAX;
        for(int i=0; i<k; i++){
            res=min(res,dp[n-1][i]);
        }
        
        return res;
    }
};