class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<int> path;
        vector<vector<int> > res;
        vector<bool> vis(nums.size(),0);
        
        helper(res,path,nums,vis);
        
        return res;
    }
    
    void helper(vector<vector<int>> &res, vector<int> &path, vector<int> &nums,vector<bool> &vis){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(!vis[i]){
                // not use nums[i]
                vis[i]=1;
                path.push_back(nums[i]);
                helper(res,path,nums,vis);
                vis[i]=0;
                path.pop_back();
            }
        }
    }
};