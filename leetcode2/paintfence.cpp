// ref https://leetcode.com/discuss/56146/dynamic-programming-c-o-n-time-o-1-space-0ms
class Solution {
public:
    int numWays(int n, int k) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return k;
        }
        // start from n==2
        // s means dp1 sequence which last two post is same color
        // d1 and d2 means dp2 sequence which last two post is different color
        // d1 denotes dp2[i-2], d2 denotes dp2[i-1]
        int s=k,d1=k,d2=k*(k-1);
        
        for(int i=2; i<n; i++){
            s=d2;
            d2=(k-1)*(d1+d2);
            d1=s;
        }
        
        return s+d2;
    }
};