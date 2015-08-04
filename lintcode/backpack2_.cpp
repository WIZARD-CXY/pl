class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        int n=A.size();
        vector<int> dp(m+1,0);
        
        for(int i=1; i<=n; i++){
            for(int j=m; j>=0; j--){
                if(j==0){
                    dp[j]=0;
                }else{
                    if(j>=A[i-1]){
                        dp[j]=max(dp[j],dp[j-A[i-1]]+V[i-1]);
                    }
                }
            }
        }
        
        
        return dp[m];
    }
};
