class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        int l=0;
        int r=A.size();
        
        while(l<r){
            int mid=(l+r)>>1;
            
            if(A[mid]==target){
                return true;
            }
            
            if(A[l]<A[mid]){
                // l to mid range is sorted
                if(A[l]<=target && target <A[mid]){
                    r=mid;
                }else{
                    l=mid+1;
                }
            }else if (A[l]>A[mid]){
                //  mid to r is sorted 
                if(A[mid]<target && target <=A[r-1]){
                    l=mid+1;
                }else{
                    r=mid;
                }
            }else{
                //can't have a clear view just linear search
                l++;
            }
        }
        
        return false;
    }
};
