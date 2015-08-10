class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
     
    bool isPa(string &s,int i,int j){
        if(i>j){
            return f[i][j]=0;
        }
        
        if(i==j){
            return f[i][j]=1;
        }
        
        //f[i][j] has been set before
        if(f[i][j]!=-1){
            return f[i][j];
        }
        
        if(s[i]!=s[j]){
            return f[i][j]=0;
        }else{
            if(j-i==1){
                return f[i][j]=1;
            }else{
                return f[i][j]=isPa(s,i+1,j-1);
            }
        }
    }
    int minCut(string s) {
        // write your code here
        int n=s.size();
        
        if(n==0 || n==1){
            return 0;
        }
        
        f.assign(n,vector<int>(n,-1));
        
        vector<int> dp(n);
        
        //dp[i] means s[0..i] min cut for palindrome
        //first initial it as worst case 
        for(int i=0; i<n; i++){
            dp[i]=i;
        }
        
        //dp[i]=min(dp[k]+1,dp[k]+i-k) ( 0<=k<i)
        // dp[k]+1 means the s[k+1..i] is palindrome
        // dp[k]+i-k means the worst cut, cut every char
        
        for(int i=1; i<n; i++){
            if(isPa(s,0,i)){
                dp[i]=0;//do not use a cut
            }else{
                for(int k=0; k<i; k++){
                    int temp;
                    if(isPa(s,k+1,i)){
                        temp=dp[k]+1;
                    }else{
                        temp=dp[k]+i-k;
                    }
                    dp[i]=min(dp[i],temp);
                }
            }
        }
        return dp[n-1];
        
    }
    vector<vector<int> > f;
};


