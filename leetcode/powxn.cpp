class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            return 1.0/hispow(x,-n);
        }else{
            return hispow(x,n);
        }
    }
    double hispow(double x,int n){
        //this n is always positive or 0
        if(n==0){
            return 1;
        }
        
        if(n==1){
            return x;
        }
        
        double temp= myPow(x,n>>1);
        
        double res=temp*temp;
        
        if(n&1){
            res*=x;
        }
        return res;
    }
};