class Solution {
public:
    int helper(int a, int b, char op){
        //only calculate * and /
        switch (op){
            case '*':
                return a*b;
            case '/':
                return a/b;
            default:
                return 0;
        }
    }
    int calculate(string s) {
        stack<char> op_stk;
        stack<int> val_stk;
        int n=s.size();
        
        int res=0;
        op_stk.push('+');
        
        for(int i=0; i<n;){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                op_stk.push(s[i]);
                i++;
            }else if(s[i]==' '){
                i++;
            }else{
                //digit
                int right=0;
                while(i<n && s[i]>='0' && s[i]<='9'){
                    right=right*10+s[i]-'0';
                    i++;
                }
                
                // do some cal using * and /
                if(!op_stk.empty() && (op_stk.top()=='*' || op_stk.top()=='/')){
                    int left=val_stk.top();
                    right=helper(left,right,op_stk.top());
                    val_stk.pop();
                    op_stk.pop();
                }
                val_stk.push(right);
            }
        }
        
        while(!op_stk.empty() && !val_stk.empty()){
            int tmp=val_stk.top();
            if(op_stk.top()=='-'){
                tmp=-tmp;
            }
            
            res+=tmp;
            op_stk.pop();
            val_stk.pop();
        }
        
        return res;
    }
};