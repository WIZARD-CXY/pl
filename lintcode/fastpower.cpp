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
        
        //long long here avoid oveflow of res
        long long res=fastPower(a,b,n>>1)%b;
        
        res=(res*res)%b;
        
        if(n&1){
            res=res*a%b;
        }
    
        return res;
    }
};
