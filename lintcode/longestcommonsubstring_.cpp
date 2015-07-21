class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int alen=A.size();
        int blen=B.size();
        
        // dp[i][j] means A[0..i) and B[0,j)'s longest common substring length
        // includes the A[i-1] and B[j-1] 
        vector<int> dp(blen+1,0);
        
        int res=0;
        for(int i=1; i<=alen; i++){
            for(int j=blen; j>=0; j--){
                if(A[i-1]==B[j-1]){
                    dp[j]=dp[j-1]+1;
                }else{
                    dp[j]=0;
                }
                res=max(res,dp[j]);
            }
        }
        
        return res;
    }
};

