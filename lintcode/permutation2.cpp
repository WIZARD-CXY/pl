class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int> > res;
        
        if(nums.size()==0){
            return res;
        }
        
        sort(nums.begin(),nums.end());

        vector<int> path;
        vector<bool> vis(nums.size(),0);
        
        helper(res,path,nums,vis);
        
        return res; 
    }
    
    void helper(vector<vector<int> > &res, vector<int> &path, vector<int> &nums, vector<bool> &vis){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(vis[i] || (i!=0 && nums[i]==nums[i-1]) && vis[i-1]){
                //current number is same with previous one and previous one is visited
                continue;
            }
            
            path.push_back(nums[i]);
            vis[i]=1;
            helper(res,path,nums,vis);
            vis[i]=0;
            path.pop_back();
        }
    }
};
