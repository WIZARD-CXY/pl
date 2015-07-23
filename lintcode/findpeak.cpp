class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int l=0;
        int r=A.size();
        if(A.size()<3){
            return -1;
        }
        
        while(l<r){
            int mid=(l+r)>>1;
            
            if(A[mid]<A[mid-1]){
                //peak is in the left side
                r=mid;
            }else if(A[mid]<A[mid+1]){
                //peak is in the right side
                l=mid;
            }else{
                return mid;
            }
        }
        
    }
};

