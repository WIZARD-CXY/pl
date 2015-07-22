class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        int l=1;
        //sqrt(x) is in range 1~(x/2+1)
        // note avoid overflow divide first
        int r=x/2+1;
        
        while(l<r){
            int mid=(l+r)/2;
            if(mid==x/mid){
                return mid;
            }else if(mid > x / mid){
                r=mid;
            }else{
                l=mid+1;
            }
        }
       
        return l-1;
    }
};
