class Solution {
public:
    vector<string> mapping={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return res;
        }
        string sub="";
        helper(sub,digits);
        
        return res;
        
    }
    
    void helper(string &sub, string digits){
        if(sub.size()==digits.size()){
            res.push_back(sub);
            return;
        }
        int i=digits[sub.size()]-'0';
        
        for(int j=0; j<mapping[i-2].size(); j++){
            sub.push_back(mapping[i-2][j]);
            helper(sub,digits);
            sub.pop_back();
        }
    }
};