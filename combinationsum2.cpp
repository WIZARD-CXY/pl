class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        vector<int> path;
        dfs(candidates,path,0,target);
        
        return res;
    }
    
    void dfs(vector<int> &candidates, vector<int> &path, int start, int target){
        if(target==0){
            res.push_back(path);
            return;
        }
        
        int previous=-1;
        
        for(int i=start ; i<candidates.size(); i++){
            if(target < candidates[i]){
                return; //prune
            }
            
            if(candidates[i]==previous){
                continue;
            }
            path.push_back(candidates[i]);
            previous=candidates[i];
            dfs(candidates,path,i+1,target-candidates[i]);
            path.pop_back();
        }
    }
};