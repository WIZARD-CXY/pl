class Stack {
public:
    queue<int> qq[2];
    int cur=0;
    // Push element x onto stack.
    void push(int x) {
        qq[cur].push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(qq[cur].size()>1){
            qq[1-cur].push(qq[cur].front());
            qq[cur].pop();
        }
        qq[cur].pop();
        cur=1-cur;
    }

    // Get the top element.
    int top() {
        // move all element to the other queue
        while(qq[cur].size()>1){
            qq[1-cur].push(qq[cur].front());
            qq[cur].pop();
        }
        int x = qq[cur].front();
        qq[1-cur].push(x);
        qq[cur].pop();
        cur=1-cur;
        
        return x;
    }

    // Return whether the stack is empty.
    bool empty() {
        return qq[cur].empty();
    }
};