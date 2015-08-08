class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        int n=A.size();
        //dp[i] means the through [0..i) the house the maximum value you can get
        vector<long long> dp(n+1);
        dp[0]=0;
        //dp[]
        dp[1]=A[0];
        
        for(int i=2; i<=n; i++){
            dp[i]=max(A[i-1]+dp[i-2],dp[i-1]);
        }
        
        return dp[n];
    }
};
