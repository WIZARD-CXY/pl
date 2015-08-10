class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int minprice=INT_MAX;
        int res=0;
        
        for(auto price : prices){
            minprice=min(minprice,price);
            int profit=price-minprice;
            
            res=max(profit,res);
            
        }
        
        return res;
    }
};

