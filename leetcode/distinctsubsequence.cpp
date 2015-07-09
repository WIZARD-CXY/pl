class Solution {
public:
    //ref http://www.cnblogs.com/ganganloveu/p/3836519.html
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        
        //dp[i][j] means that s[0,i) transfer to t[0,j)'s method
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        
        //任意一个字符串变换成一个空串都只有一种变换方法 delete all chars
        for(int i=0; i<=m; i++){
            dp[i][0]=1;
        }
        
        //fill the dp
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==t[j-1]){
                    //take s[i-1] or not
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }else{
                    //do not take s[i-1]
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][n];
        
    }
};