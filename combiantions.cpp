class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int>> combine(int n, int k) {
        if(n<k || n<1 || k<1){
            return res;
        }
        vector<int> path;
        dfs(1, n, k, path);
        return res;
    }
    
    void dfs(int start,int n,int k, vector<int> &path){
        if(path.size()==k){
            res.push_back(path);
            return;
        }
        
        for(int i=start; i<=n; i++){
            path.push_back(i);
            dfs(i+1,n,k,path);
            path.pop_back();
        }
    }
};