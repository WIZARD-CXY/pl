class Solution {
public:
    /**
     * @param nums an integer array and all positive numbers, no duplicates
     * @param target an integer
     * @return an integer
     */
    int backPackVI(vector<int>& nums, int target) {
        // Write your code here
        vector<int> dp(target+1,0);
        dp[0]=1;
        
        for(int i=1; i<=target; i++){
            for (auto num : nums){
                if(num<=i){
                    dp[i]+=dp[i-num];
                }
            }
        }
        
        return dp[target];
    }
};