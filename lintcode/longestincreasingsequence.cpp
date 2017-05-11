class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int n= nums.size();
        
        if(n==0){
            return 0;
        }
        
        // dp[i] denotes the lis size ending with nums[i]
        // originallu every dp[i] is 1
        vector<int> dp(n,1);
        int res=1;
        
        for(int i=1; i<n; i++){
            for (int j=0;j<i; j++){
                if (nums[j]<nums[i] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            
            res=max(res,dp[i]);
        }
        
        return res;
        
    }
};
