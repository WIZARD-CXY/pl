class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.size()==0){
            return true;
        }

        //dp[i] means 0~i-1 is breakable
        vector<bool> dp(s.size()+1,0);
        
        dp[0]=1;
        
        // find the max len of word in dict for pruning
        
        int maxwordlen=INT_MIN;
        for(auto word : wordDict){
            maxwordlen=max(maxwordlen,int(word.size()));
        }
        
        for(int i=0; i<s.size(); i++){
            if(dp[i]){
                //try string after i,varies in length
                for (int len=1; i+len <s.size()+1; len++){
                    if(len>maxwordlen){
                        break;
                    }
                    if(wordDict.find(s.substr(i,len))!=wordDict.end()){
                        //string after is breakable
                        dp[i+len]=1;
                    }
                }
            }
            if(dp[s.size()]){
                return true; // if ok return early
            }
        }
        return false;
    }
};