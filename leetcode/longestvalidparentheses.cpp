class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        
        // set up mm[i] means s[i] is a valid parentheses
        vector<bool> mm(n,false);
        
        stack<int> ss;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                // just push it int stack
                ss.push(i);
            }else if(s[i]==')' && !ss.empty()){
                mm[i]=1;
                mm[ss.top()]=1;
                ss.pop();
            }
        }
        
        //collect the max valid len
        int maxlen=0,curlen=0;
        
        for(int i=0; i<n; i++){
            if(mm[i]){
                curlen++;
            }else{
                curlen=0;
            }
            maxlen=max(maxlen,curlen);
        }
        return maxlen;
    }
};