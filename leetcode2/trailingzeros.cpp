class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        
        while(n){
            res+=n/5;
            n=n/5;
        }
        return res;
    }
};