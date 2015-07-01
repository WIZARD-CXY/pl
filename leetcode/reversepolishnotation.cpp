class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> ss;
        int temp1,temp2;
        
        for(int i=0; i<tokens.size(); i++){
            
            if(ss.empty() || (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")){
                ss.push(stoi(tokens[i]));
            }else if(tokens[i] == "+"){
                temp1 = ss.top();
                ss.pop();
                temp2 = ss.top();
                ss.pop();
                ss.push(temp1+temp2);
            }else if(tokens[i] == "-"){
                temp1 = ss.top();
                ss.pop();
                temp2 = ss.top();
                ss.pop();
                ss.push(temp2-temp1);
            }else if(tokens[i] == "*"){
                temp1 = ss.top();
                ss.pop();
                temp2 = ss.top();
                ss.pop();
                ss.push(temp1*temp2);
            }else if(tokens[i] == "/"){
                temp1 = ss.top();
                ss.pop();
                temp2 = ss.top();
                ss.pop();
                ss.push(temp2/temp1);
            }
            
        }
        return ss.top();
        
    }
};