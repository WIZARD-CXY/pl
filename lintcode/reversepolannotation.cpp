class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        stack<int> ss;
        int res=0;
        
        for(auto token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int a = ss.top(); ss.pop();
                int b = ss.top(); ss.pop();
                int res=compute(a,b,token);
                ss.push(res);
            }else{
                ss.push(stoi(token));
            }
        }
        
        return ss.top();
    }
    
    int compute(int a, int b, string op){
        if(op=="+"){
            return a+b;
        }else if(op=="-"){
            return b-a;
        }else if(op=="*"){
            return b*a;
        }else{
            return b/a;
        }
    }
};
