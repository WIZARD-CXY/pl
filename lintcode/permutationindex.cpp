class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        int n=A.size();
        if(n==1){
            return 1;
        }
        long long res=1;
        
        long long pos=2;
        long long factor=1;
        for(int i=n-2;i>=0; i--){
            // find to right the number of element that smaller than nums[i]
            // count is record that
            int count=0;
            for(int j=i+1; j<n; j++){
                if(A[j]<A[i]){
                    count++;
                }
            }
            res+=count*factor;
            factor*=(pos++);
        }
        
        
        return res;
    }
};
