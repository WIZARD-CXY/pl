class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        cout<<n<<endl;
        if(k>=n){
            return helper(prices);
        }
        // global[i][j] means the first i day use at most j transaction the max value we can get
        
        vector<vector<int> > global(n+1,vector<int>(k+1,0));
        // local[i][j] means the the first i day use at most j transaction and the last sell
        // happens on the last day
        vector<vector<int> > local(n+1,vector<int>(k+1,0));
        
        // diff = price[i]-price[i-1]
        //local[i][j] = max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff)
        //global[i][j]= max(global[i-1][j],local[i][j])
        
        for(int i=2; i<=n; i++){
            int diff=prices[i-1]-prices[i-2];
            for(int j=1; j<=k; j++){
                // last transaction happens on last day
                local[i][j]=max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff);
                global[i][j]=max(global[i-1][j],local[i][j]);
            }
        }
        
        return global[n][k];
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