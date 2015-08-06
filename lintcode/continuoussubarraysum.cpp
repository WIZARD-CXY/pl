class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        vector<int> res;
        int n=A.size();
        
        if(A.size()==0){
            return res;
        }
        
        int sum=A[0];
        int start=0;
        int end=0;
        
        int maxsum=A[0];
        
        int st=0;// res left
        int en=0;// res right
        
        for(int i=1; i<n; i++){
            if(sum>0){
                sum+=A[i];
                end=i;
            }else{
                // start a new subarray
                sum=A[i];
                start=i;
                end=i;
            }
            
            if(sum>maxsum){
                st=start;
                en=end;
                maxsum=sum;
            }
            
        }
        
        return {st,en};
    }
};
