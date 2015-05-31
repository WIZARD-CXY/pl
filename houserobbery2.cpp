class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        
        int dp[n+1]={0};
        
        //find the 1st to 2nd last neibourgh best val
        dp[1]=nums[0];
        
        for(int i=2;i<=n-1; i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        
        int res=dp[n-1];
        
        //find the 2nd to the last neibourgh best val, recalculate
        
        dp[2]=nums[1];
        dp[1]=0;
        
        for(int i=3; i<=n; i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        
        return max(dp[n],res);
    }
};