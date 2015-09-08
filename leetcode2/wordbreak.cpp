class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int maxlen=0;
        
        for(auto word: wordDict){
            maxlen=max(maxlen,(int)word.size());
        }

        //dp[i] indicate s[0..i] is breakable
        vector<int> dp(s.size()+1,0);
        dp[0]=1;
        
        for(int i=0; i<s.size(); i++){
            if(dp[i]){
                for(int len=maxlen; len>=1; len--){
                    if(i+len>s.size()){
                        // too large len try to make it smaller
                        continue;
                    }

                    if(wordDict.find(s.substr(i,len))!=wordDict.end()){
                        //string s[0,i+len] is also breakable
                        dp[i+len]=1;
                    }
                }
                if(dp[s.size()]){
                    return true;
                }
            }
            
        }
        return false;
    }
};