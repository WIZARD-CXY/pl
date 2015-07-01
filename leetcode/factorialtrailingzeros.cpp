class Solution {
public:
    int trailingZeroes(int n) {
        int c5=0;
        
        while(n){
            c5+=n/5;
            n/=5;
        }
        return c5;
        
    }
};