// ref http://www.cnblogs.com/easonliu/p/4563780.html
class Solution {
private:
    bool isOK(char op1, char op2) {
        if (op1 == '*' || op1 == '/' || op2 == ')') return true;
        else return op2 == '+' || op2 == '-';
    }
    int calc(int a, int b, char op) {
        if (op == '+') return a + b;
        else if (op == '-') return a - b;
        else if (op == '*') return a * b;
        else return a / b;
    }
public:
    int calculate(string s) {
        stack<int> stk_val;
        stack<char> stk_op;
        int res = 0, tmp;
        for (int i = 0; i <= s.length(); ++i) {
            //操作数
            if (i < s.length() && isdigit(s[i])) {
                res = 0;
                while (i < s.length() && isdigit(s[i])) {
                    res *= 10;
                    res += s[i++] - '0';
                }
                stk_val.push(res);
            }
            //运算符
            if (i == s.length() || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == ')') {
                while (!stk_op.empty() && stk_op.top() != '(' && (i == s.length() || isOK(stk_op.top(), s[i]))) {
                    tmp = stk_val.top();
                    stk_val.pop();
                    stk_val.top() = calc(stk_val.top(), tmp, stk_op.top());
                    stk_op.pop();
                }
                if (i == s.length()) break;
                else if (s[i] == ')') stk_op.pop();
                else stk_op.push(s[i]);
            } else if (s[i] == '(') {
                stk_op.push(s[i]);
            }
        }
        return stk_val.top();
    }
};