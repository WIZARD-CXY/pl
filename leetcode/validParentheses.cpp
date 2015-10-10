class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                ss.push(s[i]);
            }else{
                //note before poping check whether can do the pop()
                //if empty just return false mean s===']'
                if(ss.empty()){
                    return false;
                }
                char x=ss.top();
                ss.pop();
                
                if((s[i]==')' && x!='(') || (s[i]==']' && x!='[') || (s[i]=='}' && x!='{')){
                    return false;
                }
            }
        }
        
        return ss.empty();
    }
};