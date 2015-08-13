class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        
        int n=nums.size();
        if(n==0){
            return 0;
        }
        // initial dp with 1 means at least length is 1
        vector<int> dp(n,1);
        int res=1;
        // dp[i] means the longest len of num[0,i] including end
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<=nums[i] && 1+dp[j] > dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            
            res=max(res,dp[i]);
        }
        
        return res;
    }
};

