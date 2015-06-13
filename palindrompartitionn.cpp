class Solution {
public:
    vector<vector<string> > res;
    vector<string> path;
    
    bool isPalindrome(string &s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        dfs(s,0,path);
        return res;
    }
    
    //use dfs to find all the res that started fron start
    void dfs(string &s, int start,vector<string> &path){
        if(start==s.size()){
            res.push_back(path);
            return;
        }
        
        for(int i=start; i<s.size(); i++){
            if(isPalindrome(s,start,i)){
                // the start to i string is palindrom, continue to find
                path.push_back(s.substr(start,i-start+1));
                dfs(s,i+1,path);
                path.pop_back();
            }
        }
    }
};