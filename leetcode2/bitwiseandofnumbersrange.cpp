//ref http://www.cnblogs.com/csonezp/p/4587392.html
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i=0;
        
        while(m!=n){
            m>>=1;
            n>>=1;
            i++;
        }
        
        return m<<i;
    }
};