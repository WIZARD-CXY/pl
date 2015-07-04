class Solution {
public:
    bool isPal(string &s, int i, int j){
        if(i>j){
            return 0;
        }
        
        if(i==j){
            return f[i][j]=1;
        }
        
        if(f[i][j]!=-1){
            return f[i][j];
        }
        
        if(s[i]!=s[j]){
            return f[i][j]=0;
        }else{
            if(j-i==1){
                return f[i][j]=1;
            }
            return f[i][j]=isPal(s,i+1,j-1);
        }
    }
    int minCut(string s) {
        int n=s.size();
        
        if(n==0 || n==1){
            return 0;
        }
        f.assign(n,vector<int>(n,-1));
        
        //dp[i] indicate the s[0..i]'s min cut
        //dp[i]=min(d[k]+1,d[k]+i-k), 0<=k<i
        //d[k]+1 means s[k+1..i] is palindrome
        //dp[k]+i-k means s[k+1..i] is not palindrome, worst case split every char
        
        vector<int> dp;
        
        for(int i=0; i<n; i++){
            dp.push_back(i);//cut every char
        }
        
        int temp;
        for(int i=1; i<n; i++){
            if(isPal(s,0,i)){
                dp[i]=0;
            }else{
                for(int k=0; k<i; k++){
                    if(isPal(s,k+1,i)){
                        temp=dp[k]+1;
                    }else{
                        temp=dp[k]+i-k;//s
                    }
                    if(temp<dp[i]){
                      dp[i]=temp;  
                    }
                }
            }
        }
        
        return dp[n-1];
    }
    vector<vector<int> > f;
};