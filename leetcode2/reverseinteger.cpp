class Solution {
public:
    int reverse(int x) {
        int sign=1;
        if(x<0){
            sign=-1;
            if(x==INT_MIN){
                return 0;
            }
            x=-x;
        }
        
        long long res=0;
        while(x){
            res=res*10+x%10;
            x/=10;
            
            if(res>INT_MAX){
                return 0;
            }
        }
        
        return sign*res;
    }
    
};