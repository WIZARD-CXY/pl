class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        
        int n=prices.size();
        //cut the array to two
        
        //lmax[i] records prices[0..i] the max profit using one trasaction
        vector<int> lmax(n,0);
        
        int leftmin=INT_MAX;
        int lmaxx=0;
        for(int i=0; i<n; i++){
            leftmin=min(leftmin,prices[i]);
            lmaxx=max(prices[i]-leftmin,lmaxx);
            lmax[i]=lmaxx;
        }
        
        //rmax[i] records prices[i..n-1] the maxprofit using one trasaction
        int rightmax=INT_MIN;
        int rmaxx=0;
        vector<int> rmax(n,0);
        
        for(int i=n-1; i>=0; i--){
            rightmax=max(rightmax,prices[i]);
            rmaxx=max(rightmax-prices[i],rmaxx);
            rmax[i]=rmaxx;
        }
        
        //choose the cut point
        int res=0;
        for(int i=0; i<n;i++){
            res=max(res,lmax[i]+rmax[i]);
        }
        
        return res;
        
    }
};
