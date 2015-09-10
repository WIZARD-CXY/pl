class MinStack {
public:
    void push(int x) {
        ss.push(x);
       
        if(helper.empty() || x<=helper.top()){
            helper.push(x);
        }
    }

    void pop() {
        int tmp=ss.top();
        if(tmp==helper.top()){
            helper.pop();
        }
        ss.pop();
    }

    int top() {
        return ss.top();
    }

    int getMin() {
        return helper.top();
    }
    stack<int> ss;
    stack<int> helper;
};