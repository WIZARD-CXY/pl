class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        for(int k=i; k<=j; k++){
            if(m&(1<<(k-i))){
                n|=(1<<k);
            }else{
                n&=~(1<<k);
            }
        }
        return n;
    }
};
