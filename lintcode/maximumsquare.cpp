class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        int m=matrix.size();
        if(m==0){
            return 0;
        }
        
        int n=matrix[0].size();
        if(n==0){
            return 0;
        }
        //dp[i][j] records the end point is matrix[i][j]'s largest len.
        vector<vector<int> > dp(m,vector<int>(n));
        int largestlen=0;
        //dp[i][j]=matrix[i][j]==1?(min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1):0
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0){
                    dp[i][j]=matrix[i][j];
                }else{
                    dp[i][j]=matrix[i][j]==1?(min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1):0;
                }
                largestlen=max(largestlen,dp[i][j]);
            }
        }
       
       return largestlen*largestlen;
    }
};
