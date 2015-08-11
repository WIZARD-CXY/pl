class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        int n=A.size();
        
        vector<vector<vector<int>>> d(k+1,vector<vector<int>>(n+1,vector<int>(target+1,0)));
        // dp[i][j][v] means the ways of selecting i elements from first j element which
        // sums to k
        
        for(int i=1; i<=n; i++){
            if(A[i-1]<=target){
                // not overflow
                for(int j=i; j<=n; j++){
                    // selecting 1 element from j(>=i elment ways is 1)
                   d[1][j][A[i-1]]=1;
                }
            }
        }
        //d[i][j][v]=d[i-1][j-1][v-A[j-1]+d[i][j-1][v]
        // it means two ops first is select j-th element.second is not select it
        for(int i=2; i<=k; i++){
            for(int j=i; j<=n; j++){
                for(int v=1; v<=target; v++){
                    d[i][j][v]=d[i][j-1][v];
                    if(v>=A[j-1]){
                        d[i][j][v]+=d[i-1][j-1][v-A[j-1]];
                    }
                }
            }
        }
    
        return d[k][n][target];
    }
};
