class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int> > res;
        vector<int> factors;
        
        if(n<=1){
            return res;
        }
        
        helper(res,factors,n,2,1);
        
        return res;
    }
    void helper(vector<vector<int> > &res, vector<int> &factors, int n,int start,int product){
        if(product==n){
            //reach the end
            res.push_back(factors);
            return;
        }
        
        for(int i=start; i<=(n/2); i++){
            //prune
            if(product*i>n){
                return;
            }
            
            if(n%i!=0){
                continue;
            }
            factors.push_back(i);
            helper(res,factors,n,i,product*i);
            factors.pop_back();
        }
    }
};