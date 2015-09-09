class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n=s.size();
        
        vector<bool> dp(n+1,0);
        int maxlen=0;
        int minlen=INT_MAX;
        vector<string> res;
        string path;
        
        for(auto word :wordDict){
            maxlen=max(maxlen,int(word.size()));
            minlen=min(minlen,int(word.size()));
        }

        dp[0]=1;
        
        for(int i=0; i<s.size(); i++){
            if(dp[i]){
                //try to search 
                for(int len=maxlen; len>=minlen; len--){
                    if(i+len>s.size()){
                        continue;
                    }
                    if(wordDict.find(s.substr(i,len))!=wordDict.end()){
                        dp[i+len]=1;
                    }
                }
                
            }
        }
        if(dp[s.size()]==1){
           helper(res,path,s,wordDict,dp,0,maxlen,minlen); 
        }
        
        return res;
    }
    void helper(vector<string> &res, string path, string &s,unordered_set<string> &wordDict,vector<bool> &dp,int start,int maxlen ,int minlen){
        if(start==s.size()){
            res.push_back(path);
            return;
        }
        
        for(int len=minlen; start+len<=s.size()&&len<=maxlen; len++){
            string ss=s.substr(start,len);
            // if dp[start] means [0..start] is breakable and s[start...start+len-1] is in dict 
            if(dp[start] && wordDict.find(ss)!=wordDict.end()){
                if(path.empty()){
                    helper(res,ss,s,wordDict,dp,start+len,maxlen,minlen);
                }else{
                    helper(res,path+" "+ss,s,wordDict,dp,start+len,maxlen,minlen);
                }
            }
        }
    }
};