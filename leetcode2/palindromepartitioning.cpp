class Solution {
public:
    bool ispalin(string &s){
        int i=0;
        int j=s.size()-1;
        
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> path;
        
        helper(res,path,0,s);
        return res;
    }
    
    void helper(vector<vector<string> > &res, vector<string> &path, int start, string &s){
        if(start==s.size()){
            res.push_back(path);
            return;
        }
        
        for(int len=1; start+len<=s.size(); len++){
            string part=s.substr(start,len);
            if(ispalin(part)){
                path.push_back(part);
                helper(res,path,start+len,s);
                path.pop_back();
            }
        }
    }
};