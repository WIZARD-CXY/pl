class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        
        int i=0;
        
        while(i<s.size()){
            if(s[i]=='(' || s[i]=='[' || s[i] =='{'){
                ss.push(s[i]);
            }else{
                if(ss.empty()){
                    return false;
                }
                char tmp=ss.top();
                ss.pop();
                if((s[i]==')' && tmp != '(') || (s[i]==']' && tmp != '[') || s[i]=='}' && tmp != '{'){
                    return false;
                }
            }
            i++;
        }
        
        return ss.empty();
        
    }
};