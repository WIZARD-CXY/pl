class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<int> path;
        vector<vector<int> > res;
        
        if(nums.size()==0){
            return res;
        }
        
        helper(res, path, nums);
        return res;
    }
    
    void helper(vector<vector<int> > &res, vector<int> &path, vector<int> &nums){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        
        for(auto num : nums){
            auto pos = find(path.begin(),path.end(),num);
            //if num is not used in path, then use it
            if(pos==path.end()){
                path.push_back(num);
                helper(res,path,nums);
                path.pop_back();
            }
            
            //if num is used try next num
        }
    }
};

