//ref http://www.cnblogs.com/grandyang/p/4295761.html
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()<2){
            return 0;
        }
        
        if(k>=prices.size()){
            //if k is larger then reduce to best 2
            return maxProfit2(prices);
        }
        
        int l[k+1]={0};// local optimal
        int g[k+1]={0};// global optimal
        
        for(int i=1; i<prices.size(); i++){
            int diff=prices[i]-prices[i-1];
            for(int j=k; j>=1; j--){
                // from tail to head update , avoid corruption
                l[j]=max(g[j-1]+max(diff,0),l[j]+diff);
                g[j]=max(g[j],l[j]);
            }
        }
        
        return g[k];
    }
    
    int maxProfit2(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int res=0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>prices[i-1]){
                res+=prices[i]-prices[i-1];
            }
        }
        return res;
        
    }
};
