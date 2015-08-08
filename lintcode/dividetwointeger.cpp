class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        if(dividend==INT_MIN && divisor ==-1) return INT_MAX;
        long long a=labs(dividend);
        long long b=labs(divisor);
        
        int res=0;

        while(a>=b){
            long long c=b;
            // every iteration try c=2*c
            for(int i=0; a>=c; i++,c<<=1){
                a-=c;
                res+=1<<i;
            }
        }

        return ((dividend^divisor)>>31)?(-res):res;
    }
};
