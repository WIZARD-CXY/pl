class Solution {
public:
    void helper(vector<vector<int>> &res,vector<int> &path,int n){
        int i=path.empty()?2:path.back();
        
        for(;i<=n/i;++i){
            if(n%i==0){
                path.push_back(i);
                path.push_back(n/i);
                
                res.push_back(path);
                path.pop_back();
                
                helper(res,path,n/i);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<vector<int> > res;
        vector<int> path;
        
        helper(res,path,n);
        
        return res;
    }
};