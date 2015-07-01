class Solution {
public:
    int mySqrt(int x) {
        if(x<0){
            return -1;
        }
        long long l = 0;
        long long r = x/2 + 2;
        
        while(l < r){
            long long mid = (l+r)/2;
            long long tmp = mid * mid;
            if(tmp == x) return mid;
            else if(tmp > x) r = mid;
            else l = mid + 1;
        }
        
        // not found sqrt(x) directly. change a little bit
        // l is the upper_bount of sqrt(n)
        
        return l-1;
    }
};