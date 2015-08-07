class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> temp;
        while(!s.empty()){
            //pop all the s elements to temp
            temp.push(s.top());
            s.pop();
        }
        s.push(x);
        
        //pop back
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s.pop();
    }

    // Get the front element.
    int peek(void) {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
    
    // return the last element
    int back() {
        stack<int> temp;
        while(!s.empty()){
            //pop all the element to temp
            temp.push(s.top());
            s.pop();
        }
        return temp.top();
    }
private:
    stack<int> s;
};