class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Polish notation of this expression
     */
    vector<string> convertToPN(vector<string> &expression) {
        vector<string> output;
        infixToPrefix(expression, output);
        return output;
    }

    // Convert Infix to Prefix Expression.
    void infixToPrefix(vector<string>& infix, vector<string>& prefix) {
        reverse(infix.begin(), infix.end());
        stack<string> s;
        for (auto& token : infix) {
            if (atoi(token.c_str())) {
                //if token is number
                prefix.push_back(token);
            } else if (token == ")") {
                s.push(token);
            } else if (token == "(") {
                while (!s.empty()) {
                    token = s.top();
                    s.pop();
                    if (token == ")") {
                        break;
                    }
                    prefix.push_back(token);
                }
            } else {
                // operator
                while (!s.empty() && precedence(token) < precedence(s.top())) {
                    prefix.push_back(s.top());
                    s.pop();
                }
                s.push(token);
            }
        }
        while (!s.empty()) {
            prefix.push_back(s.top());
            s.pop();
        }
        reverse(prefix.begin(), prefix.end());
    }

    int precedence(string x) {
        if (x == ")") {
            return 0;
        } else if (x == "+" || x == "-") {
            return 1;
        } else if (x == "*" || x == "/") {
            return 2;
        }
        return 3;
    }
};
