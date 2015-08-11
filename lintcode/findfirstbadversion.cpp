/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    // just get lower_bound 
    // ok ok ok wrong wrong wrong return first version is wrong
    int findFirstBadVersion(int n) {
        // write your code here
        int l=1;
        int r=n+1;
        
        while(l<r){
            int m=(l+r)>>1;
            
            if(VersionControl::isBadVersion(m)){
                r=m;
            }else{
                l=m+1;
            }
        }
        return l;
    }
};

