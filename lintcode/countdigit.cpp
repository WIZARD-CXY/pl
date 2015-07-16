class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
     // caution if k is 0 this solution is infact wrong
    int digitCounts(int k, int n) {
        // write your code here
        int res=0;
        int base=1;
        
        while(n/base){
            int cur=(n/base)%10;
            int low=n%base;
            int high=n/base/10;
            
            if (cur<k){
                res+=high*base;
            }else if(cur>k){
                res+=(high+1)*base;
            }else{
                res+=high*base+low+1;
            }
            base*=10;
        }
        
        return res;
    }
};
