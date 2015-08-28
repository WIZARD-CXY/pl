class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            // in case n==INT_MIN promot to long long
            return 1.0/helper(x,-n);
        }
        return helper(x,n);
    }
    
    double helper(double x, long long n){
        if(n==0){
            return 1.0;
        }
        
        if(n==1){
            return x;
        }
        
        double tmp=helper(x,n/2);
        double res=tmp*tmp;
        
        if(n&1){
            res*=x;
        }
        
        return res;
    }
};