class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i=0;
        while(n!=m){
            n>>=1;
            m>>=1;
            i++;
        }
        return m<<i;
    }
};