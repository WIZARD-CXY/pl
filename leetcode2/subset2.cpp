class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        vector<int> path;
        
        helper(res,path,nums,0);
        return res;
    }
    
    void helper(vector<vector<int> > &res, vector<int> &path, vector<int> &nums, int start){
        res.push_back(path);
        
        for(int i=start; i<nums.size(); i++){
            if(i==start || nums[i]!=nums[i-1]){
                path.push_back(nums[i]);
                helper(res,path,nums,i+1);
                path.pop_back();
            }
        }
    }
};