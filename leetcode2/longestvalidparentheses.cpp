class Solution {
public:
    int longestValidParentheses(string s) {
    
        stack<int> ss;
        int n=s.size();
        int curlen=0;
        int maxlen=0;

        //use extra mm[i] indicate ith parenthese is ok
        vector<bool> mm(n,0);
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                ss.push(i);
            }else{
                //s[i]=')'
                if(ss.empty()){
                }else{
                    int tmp=ss.top();
                    ss.pop();
                
                    if(s[tmp]=='('){
                      mm[i]=1;
                      mm[tmp]=1;
                    }
                }
                
            }
            
        }
        
        for(int i=0; i<s.size(); i++){
            if(mm[i]==1){
                curlen++;
                maxlen=max(maxlen,curlen);
            }else{
                curlen=0;
            }
        }
        return maxlen;
        
    }
};