class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if(n==0){
            return 1%b;
        }
        if(n==1){
            return a%b;
        }
        
        int res=fastPower(a,b,n>>1)%b;
        // when multiply first convert to long long
        res=(long long)res*res%b;
        
        if(n&1){
            res=(long long)res*a%b;
        }
    
        return res;
    }
};
