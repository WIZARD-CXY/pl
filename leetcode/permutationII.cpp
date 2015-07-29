class Solution {
public:
    vector<vector<int> > res;
    void solve(int n, vector<int> &temp, vector<int> &nums,vector<bool> &used){
        if(temp.size()==n){
            res.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
    
            if(used[i] || (i!=0 && nums[i-1]==nums[i] && used[i-1]) ){
                continue;
            }
    
            temp.push_back(nums[i]);
            used[i]=1;
            solve(n,temp,nums,used);
            used[i]=0;
            temp.pop_back();  
        }
    }
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),0);
        vector<int> temp;
        
        solve(nums.size(),temp,nums,used);
        
        return res; 
        
    }
};