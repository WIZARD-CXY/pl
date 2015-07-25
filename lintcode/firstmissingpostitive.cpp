class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        int n=A.size();
        
        for(int i=0; i<n; i++){
            // move until we get A[i]=i+1 or A[i] <0 or A[i]> n or 
            // A[i]==A[A[i]-1] just need not swap
            while(A[i]!=i+1){
                if(A[i]<=0 || A[i] >n || A[i]==A[A[i]-1]){
                    break;
                }
                swap(A[i],A[A[i]-1]);
            }
        }
        
        // the A[i]!=i+1 element is missing
        for(int i=0; i<n; i++){
            if(A[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};
