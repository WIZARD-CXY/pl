class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0){
            return res;
        }
        vector<string> books={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        string path;
        
        helper(path, books, res,0,digits);
        
        return res;
    }
    void helper(string &path, vector<string> &books, vector<string> &res, int start, string digits){
        if(path.size()==digits.size()){
            res.push_back(path);
            return;
        }
        
        for(int i=0; i<books[digits[start]-'2'].size(); i++){
            path+=books[digits[start]-'2'][i];
            helper(path, books, res, start+1, digits);
            path.erase(path.end()-1);
        }
    }
};