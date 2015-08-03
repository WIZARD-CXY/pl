class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int n=A.size();
        
        if(n==0){
            return 0;
        }
        // at least one result
        int res=1;
        int count=1;
        
        // left to right
        for(int i=1; i<n; i++){
            if(A[i]>=A[i-1]+1){
                count++;
            }else{
                count=1;
            }
            res=max(res,count);
        }
        
        //  right to left
        count=1;
        for(int i=n-2; i>=0; i--){
            if(A[i]>=A[i+1]+1){
                count++;
            }else{
                count=1;
            }
            res=max(res,count);
        }
        
        return res;
    }
};
