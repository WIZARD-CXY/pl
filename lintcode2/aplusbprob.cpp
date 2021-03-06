class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        while(b!=0){
            //b works as carry
            int carry = a&b;
            // a works as temp result
            a=a^b;
            b=carry<<1;
        }
        
        return a;
    }
};
