class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> path;
        
        helper(path,0,nums);
        
        return res;     
    }
    
    void helper(vector<int> &path,int cur,vector<int> &nums){
        if(cur==nums.size()){
            res.push_back(path);
            return;
        }
        
        // not select the cur
        helper(path,cur+1,nums);
        
        //select the cur
        
        path.push_back(nums[cur]);
        helper(path,cur+1,nums);
        path.pop_back();
    }
};