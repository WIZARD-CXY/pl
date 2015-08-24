class Solution {
public:
    int divide(int dividend, int divisor) {
        //handle overflow
        if(dividend==INT_MIN && divisor ==-1) return INT_MAX;
        //convert to positive
        long long a=labs(dividend);
        
        long long d=labs(divisor);
        
        int res=0;
        while(a>=d){
            // promot to long long in case "2147483647, 1"
            long long  b=d;
            
            for(int i=0; a-b>=0; i++){
                a=a-b;
                res+=(1<<i);
                b<<=1;
            }
            
        }
        
        return ((dividend^divisor)>>31)?-res:res;
        
    }
};