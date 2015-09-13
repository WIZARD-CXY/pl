class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        return max(helper(nums,0,nums.size()-2),helper(nums,1,nums.size()-1));
    }
    // helper function to calculate the max rob we can get from robbing nums [l..r]
    int helper(vector<int> &nums,int l, int r){
        vector<int> dp(r-l+2);
        
        dp[0]=0;
        dp[1]=nums[l];
        
        for(int i=2; i<=(r-l+1); i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1+l]);
        }
        
        return dp[r-l+1];
    }
};