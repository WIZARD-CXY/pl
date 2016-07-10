/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        // push from back to head to the stack
        for(int i=nestedList.size()-1; i>=0; i--){
            s.push(nestedList[i]);
        }
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        NestedInteger res=s.top();
        s.pop();
        return res.getInteger();
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        while(!s.empty()){
            // get the element from stack s
            NestedInteger x=s.top();
            if(x.isInteger()){
                return true;
            }
             // x is a nested list
            // get rid of the old nested list
            s.pop();
            // push from back to front of the x
            auto intlist=x.getList();
            for(int i=intlist.size()-1; i>=0; i--){
                s.push(intlist[i]);
            }
            
        }
        
        return false;
    }
    stack<NestedInteger> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */