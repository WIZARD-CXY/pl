class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& A, int start, int end) {
        // Write your code here
        
        //sum[i] means the sum from 0 to i-1
        int n=A.size();
        vector<int> sum(n+1,0);
        
        for(int i=1; i<=n; i++){
            sum[i]=sum[i-1]+A[i-1];
        }
        
        int count=0;
        for(int i=1; i<=A.size(); i++){
            for(int j=i; j<=A.size(); j++){
                if((sum[j]-sum[i-1])>=start && (sum[j]-sum[i-1])<=end){
                    count++;
                }
            }
        }
        
        return count;
    }
    
};