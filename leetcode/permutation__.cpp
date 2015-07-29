class Solution {
public:
    vector<vector<int> > res;

    void permutate(vector<int> &nums,vector<int> &temp){
        if(temp.size()==nums.size()){
           res.push_back(temp);
           return;
        }
        
        for(int i=0; i<nums.size(); i++){
            auto pos =find(temp.begin(),temp.end(),nums[i]);
            
            if(pos==temp.end()){
                temp.push_back(nums[i]);
                permutate(nums,temp);
                temp.pop_back();
            }
            
        }
    }
    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> temp;
        permutate(nums,temp);
        return res;
    }
};