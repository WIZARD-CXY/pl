class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        int a=1;
        int b=1;
        if(n==1){
            return 1;
        }
        int c;
        for(int i=2; i<=n; i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};