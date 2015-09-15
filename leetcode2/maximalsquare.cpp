class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0){
            return 0;
        }
        
        int n=matrix[0].size();
        if(n==0){
            return 0;
        }
        
        int res=0;
        vector<vector<int> > dp(m,vector<int>(n,1));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0){
                    //first row and first col
                    dp[i][j]=matrix[i][j]-'0';
                }else{
                    if(matrix[i][j]=='0'){
                        dp[i][j]=0;
                    }else{
                        dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                    }
                }
                
                res=max(res,dp[i][j]);
            }
        }
        
        return res*res;
    }
};