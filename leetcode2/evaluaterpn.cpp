class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ss;
        for(auto t :tokens){
            if(ss.empty() || (t!="+" && t!="-" && t!="*" && t!="/")){
                ss.push(stoi(t));
            }else if (t=="+"){
                int a=ss.top();
                ss.pop();
                int b=ss.top();
                ss.pop();
                
                ss.push(a+b);
            }else if (t=="-"){
                int a=ss.top();
                ss.pop();
                int b=ss.top();
                ss.pop();
                
                ss.push(b-a);
            }else if (t=="*"){
                int a=ss.top();
                ss.pop();
                int b=ss.top();
                ss.pop();
                
                ss.push(a*b);
            }else{
                int a=ss.top();
                ss.pop();
                int b=ss.top();
                ss.pop();
                
                ss.push(b/a);
            }
        }
        return ss.top();
    }
};