class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0){
            return 0;
        }
        
        //dp[i] records prices[0..i] max profit
        vector<int> dp(n,0);
        int minV=prices[0];
        dp[0]=0;
        
        for(int i=1; i<n;i++){
            minV=min(minV,prices[i]);
            dp[i]=max(dp[i-1],prices[i]-minV);
        }
        
        int maxV=prices[n-1];
        vector<int> dp2(n,0);
        dp2[n-1]=0;
        
        for(int i=n-2; i>=0; i--){
            maxV=max(maxV,prices[i]);
            dp2[i]=max(dp2[i+1],maxV-prices[i]);
        }
        
        int res=0;
        for(int i=0; i<n; i++){
            res=max(res,dp[i]+dp2[i]);
        }
        
        return res;
    }
};