class Solution {
public:
    bool isValid(string s) {
        
        stack<char> ss;
        
        for(int i=0; i<s.size(); i++){
            if( s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(ss.empty()){
                    return false;
                }else{
                    char temp = ss.top();
                    ss.pop();
                    if( (s[i] == ')'  && temp!='(') || (s[i]=='}' && temp!= '{') || (s[i]==']' && temp != '[') ){
                        return false;
                    }
                }
            }else{
                ss.push(s[i]);
            }
        }
        return ss.empty();
        
    }
};