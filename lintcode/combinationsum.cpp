class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> path;
        
        dfs(res, path, candidates, target, 0);
        return res;
    }
    
    void dfs(vector<vector<int> > &res, vector<int> &path, vector<int> &candidates, int target,int start){
        if(target==0){
            res.push_back(path);
            return;
        }
        
        for(int i=start; i<candidates.size(); i++){
            if(target<candidates[i]){
                return;//prune this candidate[i] and other larger candidates since it is too large 
            }
            path.push_back(candidates[i]);
            
            dfs(res,path,candidates,target-candidates[i],i);
            path.pop_back();
        }
    }
};
