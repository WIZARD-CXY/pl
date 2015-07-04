class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        if(n<2){
            return 0;
        }
        
        int pre[n]={0};//record from 0 to i day's max profit
        int post[n]={0};//record from i to n-1 day's max profit
        
        int minV=prices[0];
        
        // note the iteration order, only sell after buy, so the two iterarion order is reversed
        // and use minV and MaxV variable
        for(int i=1; i<n; i++){
            minV=min(minV,prices[i]);
            pre[i]=max(pre[i-1],prices[i]-minV);
                               
        }
        
        int maxV=prices[n-1];
        
        for(int i=n-2; i>=0; i--){
            maxV=max(maxV,prices[i]);
            post[i]=max(post[i+1],maxV-prices[i]);
        }
        
        int res=0;
        
        for(int i=0; i<n; i++){
            res=max(res,pre[i]+post[i]);
        }
        
        return res;
    }
};