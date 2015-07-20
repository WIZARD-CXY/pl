class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        int n=nums.size();
        vector<long long> res;
        if(n==0){
            return res;
        }
        
        res.assign(n,1);
        
        // fill the left side
        for(int i=1; i<n; i++){
            res[i]=res[i-1]*nums[i-1];
        }
        
        long long right=1;
        
        for(int i=n-1; i>=0; i--){
            res[i]=res[i]*right;
            right*=nums[i];
        }
        
        return res;
    }
};
