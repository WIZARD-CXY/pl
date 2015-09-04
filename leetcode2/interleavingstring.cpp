class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.size();
        int len2=s2.size();
        int len3=s3.size();
        
        if(len1+len2!=len3){
            return false;
        }
        
        
        //dp[i][j] means if s1 [0..i) and s2[0..j) can interleave s3 [0...i+j-1)
        vector<vector<int> > dp(len1+1,vector<int>(len2+1,0));
        dp[0][0]=1; // for "","",""
        // initial first row and col
        for(int i=1; i<=len1; i++){
            if(s1[i-1]==s3[i-1]){
                dp[i][0]=1;
            }else{
                break;
            }
        }
        
        for(int j=1; j<=len2; j++){
            if(s2[j-1]==s3[j-1]){
                dp[0][j]=1;
            }else{
                break;
            }
        }
        
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                //s1-s3 tail match and s2-s3 tail match
                dp[i][j] = (s1[i-1]==s3[i+j-1] && dp[i-1][j]) || (s2[j-1]==s3[i+j-1] && dp[i][j-1]);
            }
        }
        
        return dp[len1][len2];
    }
};