http://blog.csdn.net/linhuanmars/article/details/23236995
class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here
        // dp[i][j] means the max profit we can get from 
        // prices[0..i] with j transaction
        int n=prices.size();
        if(n<2){
            return 0;
        }
        
        if(k>=n){
            return helper(prices);
        }
        
        vector<int> local(k+1,0);
        vector<int> global(k+1,0);
        
        for(int i=1; i<n; i++){
            int diff=prices[i]-prices[i-1];
            for(int j=k; j>=1; j--){
                local[j]=max(global[j-1]+max(diff,0),local[j]+diff);
                global[j]=max(global[j],local[j]);
            }
        }
        
        return global[k];
    }
    
    int helper(vector<int> &prices){
        int res=0;
        
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>prices[i-1]){
                res+=prices[i]-prices[i-1];
            }
        }
        
        return res;
    }
};
