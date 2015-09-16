class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1){
            return false;
        }
        // caution the operator precedence
        return (n&(n-1))==0;
    }
};