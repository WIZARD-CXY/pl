class Solution {
public:
    void helper(vector<string> &res, string &s, int start, string str, unordered_set<string>& dict, vector<bool> dp){
        string substr;
        for(int len=1; start+len <s.size()+1; len++){
            if(dp[start+len] && dict.find(s.substr(start,len))!=dict.end()){
                // if idx +len is breakable
                substr = s.substr(start,len);
                
                if(start+len<s.size()){
                    // move forward
                    helper(res,s,start+len,str+substr+" ",dict,dp);
                }else{
                    //reach the end
                    res.push_back(str+substr);
                    return;
                }
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        
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
        
        if(dp[s.size()]){
            //if breakable call helper
            helper(res,s,0,"",wordDict,dp);
        }
        
        return res;
    }
};