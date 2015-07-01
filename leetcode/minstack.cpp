class MinStack {
public:
    void push(int x) {
        s.push(x);
        
        if(mins.empty() || mins.top() >= x) {
            mins.push(x);
        }
        
    }

    void pop() {
        int temp = s.top();
        if(temp==mins.top()){
            mins.pop();
        }
        s.pop();    
        
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return mins.top();
        
    }
    stack<int> s;
    stack<int> mins;
};
