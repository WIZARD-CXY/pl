class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        vector<string> output;
        infixToPostfix(expression, output);
        return output;
    }

    // Convert Infix to Postfix Expression.
    void infixToPostfix(const vector<string>& infix, vector<string>& postfix) {
        stack<string> s;
        for (auto token : infix) {
            if (atoi(token.c_str())) {
                postfix.push_back(token);
            } else if (token == "(") {
                s.push(token);
            } else if (token == ")") {
                while (!s.empty()) {
                    token = s.top();
                    s.pop();
                    if (token == "(") {
                        break;
                    }
                    postfix.push_back(token);
                }
            } else {
                while (!s.empty() && precedence(token) <= precedence(s.top())) {
                    postfix.push_back(s.top());
                    s.pop();
                }
                s.push(token);
            }
        }
        while (!s.empty()) {
            postfix.push_back(s.top());
            s.pop();
        }
    }

    int precedence(string x) {
        if (x == "(") {
            return 0;
        } else if (x == "+" || x == "-") {
            return 1;
        } else if (x == "*" || x == "/") {
            return 2;
        }
        return 3;
    }
};
