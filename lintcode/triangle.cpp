class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int m=triangle.size();
        
        if(m==0){
            return 0;
        }
        
        //dp[j] means the min value we can get when start from triangle[j]
        vector<int> dp(m,0);
        
        // intial the bottom line
        for(int i=0; i<m; i++){
            dp[i]=triangle[m-1][i];
        }
        
        //fill the upper line 
        
        for(int i=m-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
            }
        }
        
        return dp[0];
    }
};

