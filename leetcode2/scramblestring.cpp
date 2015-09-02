class Solution {
public:
    bool isScramble(string s1, string s2) {
        
        if(s1.size()!=s2.size()){
            return false;
        }
        int slen=s1.size();
        // a memo
        // dp[l][i][j] indicate s1[i..i+l-1] is scramble to s2[j..j+l-1] or not
        bool dp[s1.size()+1][s1.size()][s1.size()];
        memset(dp,0,sizeof(dp));
        
        //first initial the len 1
        
        for(int i=0; i<slen; i++){
            for(int j=0; j<slen; j++){
                if(s1[i]==s2[j]){
                    dp[1][i][j]=true;
                }
            }
        }
    
        for(int len=2; len<=slen; len++){
            for(int i=0; i<=slen-len; i++){
                for(int j=0; j<=slen-len; j++){
                    //get the dp[len][i][j] from dp[k][i][j] , 1<=k<=len-1
                    dp[len][i][j]=false;
                    
                    for(int k=1; k<len && !dp[len][i][j]; k++){
                        dp[len][i][j] = dp[len][i][j] || (dp[k][i][j]&&dp[len-k][i+k][j+k]);
                        dp[len][i][j] = dp[len][i][j] || (dp[k][i][j+len-k]&&dp[len-k][i+k][j]);
                    }
                }
            }
        }
        
        return dp[s1.size()][0][0];
    }
};