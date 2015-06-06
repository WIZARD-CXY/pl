class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int>> combine(int n, int k) {
        if(n<k || n<1 || k<1){
            return res;
        }
        vector<int> path;
        for(int i=1; i<=n; i++){
            dfs(i,n,k,path);
        }
        return res;
    }
    
    void dfs(int start,int n,int k, vector<int> &path){
        if(path.size()>k){
            return;
        }
        path.push_back(start);
        if(path.size()==k){
            res.push_back(path);
        }
        
        for(int i=start+1; i<=n; i++){
            dfs(i,n,k,path);
        }
        path.pop_back();
        
    }
};