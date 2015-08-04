class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<vector<string> > res;
        vector<string> tmp;
        
        // use a dfs helper
        dfs(res,tmp,s,0);
        
        return res;

    }
    void dfs(vector<vector<string> > &res, vector<string> &tmp, string &s, int start){
        if(start==s.size()){
            res.push_back(tmp);
            return;
        }
        
        for(int len=1; start+len<=s.size(); len++){
            string ss=s.substr(start,len);
            if(isPalin(ss)){
                tmp.push_back(ss);
                dfs(res,tmp,s,start+len);
                tmp.pop_back();
            }
        }
    }
    
    bool isPalin(string &s){
        int l=0;
        int r=s.size()-1;
        
        while(l<r){
            if(s[l++]!=s[r--]){
                return false;
            }
        }
        return true;
    }
};
