class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        vector<vector<int> > res;
        
        for(int i=0; i<(1<<n); i++){
            vector<int> path;
            for(int j=0; j<n; j++){
                if(1&(i>>j)){
                    path.push_back(nums[j]);
                }
            }
            res.push_back(path);
        }
        
        return res;
    }
};