class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        
        int sign=1;
        long long res=0;
        
        if(n<0){
            sign=-1;
            n=-n;
        }
        
        while(n){
            res=res*10+n%10;
            if(sign*res>INT_MAX){
                return 0;
            }
            if(sign*res<INT_MIN){
                return 0;
            }
            n/=10;
        }
        
        return res*sign;
        
    }
};
