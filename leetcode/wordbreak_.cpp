class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        //dp[i]=1 means s[0..i) is breakable
        vector<bool> dp(s.size()+1,0);
        
        dp[0]=1;
        
        for(int i=0; i<s.size(); i++){
            if(dp[i]){
                //try string after
                for (int len=1; i+len <s.size()+1; len++){
                    if(wordDict.find(s.substr(i,len))!=wordDict.end()){
                        //string after is breakable
                        dp[i+len]=1;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};