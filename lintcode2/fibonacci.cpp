class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        int a=0;
        int b=1;
        
        // a b c format, move forward
        if(n==1){
            return a;
        }
        
        if(n==2){
            return b;
        }
        int c;
        for(int i=3; i<=n; i++){
            c=a+b;
            a=b;
            b=c;
        }
        
        return c;
    }
};

