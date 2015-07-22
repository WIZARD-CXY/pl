class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    // just get lower_bound
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int l=0;
        int r=A.size();
        
        while(l<r){
            int mid = (l+r)>>1;
            
            if(A[mid]>=target){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};
