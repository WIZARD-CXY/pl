class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        sort(num.begin(), num.end());
        
        vector<vector<int> > res;
        vector<int> path;
        
        dfs(res, path, num, target, 0);
        return res;
    }
    
    void dfs(vector<vector<int> > &res, vector<int> &path, vector<int> &num, int target, int start){
        if(target==0){
            res.push_back(path);
            return;
        }
        
        int pre=-1;// record the previous one
        for(int i=start; i<num.size(); i++){
            if(target<num[i]){
                return;// prune the large num[i];
            }
            if(num[i]==pre){
                continue;// skip the same number in the same round
            }
            path.push_back(num[i]);
            pre=num[i];
            dfs(res, path, num, target-num[i],i+1);
            path.pop_back();
        }
    }
};
