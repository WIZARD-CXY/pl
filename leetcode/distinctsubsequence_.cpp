class Solution {
public:
    //ref http://www.cnblogs.com/ganganloveu/p/3836519.html
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        
        //rolling array
        vector<int> dp(n+1,0);
        
        dp[0]=1;

        //fill the dp
        for(int i=1; i<=m; i++){
            for(int j=n; j>=1; j--){
                if(s[i-1]==t[j-1]){
                    //take s[i-1] or not
                    dp[j]=dp[j-1]+dp[j];
                }else{
                    //do not take s[i-1]
                    //dp[j]=dp[j];
                }
            }
        }
        return dp[n];
        
    }
};