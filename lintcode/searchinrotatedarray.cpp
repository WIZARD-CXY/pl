class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int l=0;
        int r=A.size();
        
        while(l<r){
            int mid=(l+r)>>1;
            
            if(A[mid]==target){
                return mid;
            }
            
            if(A[mid]>A[l]){
                // l to mid range is sorted
                if(A[l]<=target && target < A[mid]){
                    //target is in range l to mid
                    r=mid;
                }else{
                    //target is in mid to r
                    l=mid+1;
                }
            }else{
                //mid to r range is sorted
                if(A[mid]<target && target<=A[r-1]){
                    // target is in range mid to r
                    l=mid+1;
                }else{
                    // target is in l to mid
                    r=mid;
                }
            }
        }
        
        return -1;
    }
};
