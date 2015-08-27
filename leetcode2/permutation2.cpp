class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        vector<int> path;
        
        vector<bool> used(nums.size(),0);
        
        helper(res,path,nums,used);
        
        return res;
    }
    
    void helper(vector<vector<int> > &res, vector<int> &path, vector<int> &nums, vector<bool> &used){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(used[i] || i>0 && nums[i]==nums[i-1] && used[i-1]){
                // nums[i-1] is used and is the same with nums[i]
                continue;
            }
            used[i]=1;
            path.push_back(nums[i]);
            helper(res,path,nums,used);
            used[i]=0;
            path.pop_back();
        }
    }
};