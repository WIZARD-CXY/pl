class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        stack<char> ss;
        
        for(auto c: s){
            if(c=='[' || c=='(' || c=='{'){
                ss.push(c);
            }else{
                char tmp=ss.top();
                ss.pop();
                if((c==')' && tmp!='(') || (c==']' && tmp!='[') || (c=='}' && tmp!='{')){
                    return false;
                }
            }
        }
        
        return ss.empty();
    }
};
