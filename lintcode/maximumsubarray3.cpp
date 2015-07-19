class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        // write your code here
        int n=nums.size();
        
        if(n<k){
            return 0;
        }
        
        //dp[i][j]: select j subarrays from the first i elements, the max sum we can get
        
        //dp[i][j]=max{dp[p][j-1]+maxsubarrayrange(p,i-1)} (i-1=>p>= j-1)
        // split the array with j-1 subarray and 1 left array
        int dp[n+1][k+1];
        
        for(int i=0; i<n; i++){
            dp[i][0]=0;
        }
        
        for(int j=1; j<=k; j++){
            for(int i=j;i<=n; i++){
                dp[i][j]=INT_MIN;
                
                int endmax=0;
                int totalmax=INT_MIN;
                
                for(int p=i-1; p>=j-1; p--){
                    endmax=max(endmax+nums[p],nums[p]);
                    totalmax=max(totalmax,endmax);
                    
                    if(totalmax+dp[p][j-1]>dp[i][j]){
                        dp[i][j]=totalmax+dp[p][j-1];
                    }
                }
            }
        }
        
        return dp[n][k];
    }
};

