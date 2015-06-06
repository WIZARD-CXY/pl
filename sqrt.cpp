class Solution {
public:
    int mySqrt(int x) {
        if(x<0){
            return -1;
        }
        long long l = 0;
        long long r = x/2 + 1;
        
        while(l < r){
            long long mid = (l+r)/2;
            long long tmp = mid * mid;
            if(tmp == x) return mid;
            else if(tmp > x) r = mid -1;
            else l = mid + 1;
        }
        
        // not found a little
        long long temp=r*r;
        
        if(temp>x){
            return r-1;
        }else{
            return r;
        }
    }
};