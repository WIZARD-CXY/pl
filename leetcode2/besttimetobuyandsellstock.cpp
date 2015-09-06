class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minV=INT_MAX;
        int res=0;
        
        for(auto p : prices){
            minV=min(minV,p);
            res=max(res,p-minV);
        }
        return res;
    }
};