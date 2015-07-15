class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        ss.push(number);
        if(helper.empty() || number<helper.top()){
            helper.push(number);
        }else{
            helper.push(helper.top());
        }
    }

    int pop() {
        // write your code here
        int res=ss.top();
        ss.pop();
        helper.pop();
        
        return res;
    }

    int min() {
        // write your code here
        return helper.top();
    }
    stack<int> ss; // main stack
    stack<int> helper;// help stack
};

