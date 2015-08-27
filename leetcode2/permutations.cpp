class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<int> path;
        vector<vector<int> > res;
        
        helper(res,path,nums);
        
        return res;
    }
    
    void helper(vector<vector<int>> &res, vector<int> &path, vector<int> &nums){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            auto pos=find(path.begin(),path.end(),nums[i]);
            
            if(pos==path.end()){
                // not use nums[i]
                path.push_back(nums[i]);
                helper(res,path,nums);
                path.pop_back();
            }
        }
    }
};