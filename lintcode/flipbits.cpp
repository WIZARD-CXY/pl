class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int res= a^b;
        int count=0;
        while(res){
            res=res&(res-1);
            count++;
        }
        return count;
    }
};
