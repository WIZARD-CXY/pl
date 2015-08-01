class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        vector<int> B=A;
        
        //dp[i][j] means the start from index i with leading element j 's min cost
        vector<vector<int> > dp(A.size(),vector<int>(101,INT_MAX));
        
        return helper(A,B,target,0,dp);
    }
    
    // return start fron index the minimal cost
    int helper(vector<int> &A, vector<int> &B, int target, int index, vector<vector<int> > &dp){
        if(index>=A.size()){
            return 0;
        }
        
        int mindiff=INT_MAX;
        //try every elemet on B[index]
        for(int i=1; i<=100; i++){
            //try to set B[index] to i, if index is 0 free to set
            if(index!=0 && abs(i-B[index-1])>target){
                continue;
            }
            
            if(dp[index][i]!=INT_MAX){
                mindiff=min(mindiff,dp[index][i]);
                continue;
            }
            
            B[index]=i;
            int diff=abs(i-A[index]);
            diff+=helper(A,B,target,index+1,dp);
            
            dp[index][i]=diff;
            
            mindiff=min(mindiff,diff);
            
        }
    
        return mindiff;
    }
};
